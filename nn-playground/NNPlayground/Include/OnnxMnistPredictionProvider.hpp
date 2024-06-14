#ifndef ONNX_MNIST_PREDICTION_PROVIDER_HPP
#define ONNX_MNIST_PREDICTION_PROVIDER_HPP

#include <array>
#include <filesystem>
#include <onnxruntime/core/session/onnxruntime_cxx_api.h>
#include <stdexcept>
#include <vector>

namespace
{
template < std::size_t N >
constexpr std::int64_t computeSize( std::array< std::int64_t, N > const & shape )
{
    static_assert( N > 0 );
    std::int64_t result{ 1 };
    for ( const auto dim : shape )
    {
        result *= dim;
    }
    return result;
}
}  // namespace

class OnnxMnistPredictionProvider final
{
private:
    Ort::Env            env;
    Ort::SessionOptions sessionOptions;
    Ort::Session        session;
    Ort::MemoryInfo     memoryInfo;

public:
    static constexpr std::array< std::int64_t, 4 > inputShape{ 1, 28, 28, 1 };
    static constexpr std::array< std::int64_t, 2 > outputShape{ 1, 10 };
    static constexpr std::size_t                   inputSize{ computeSize( inputShape ) };
    static constexpr std::size_t                   outputSize{ computeSize( outputShape ) };

    std::array< float, inputSize >  input;
    std::array< float, outputSize > output;

public:
    explicit OnnxMnistPredictionProvider( std::filesystem::path const & modelPath ) :
        env( ORT_LOGGING_LEVEL_WARNING, "MnistPrediction" ), sessionOptions(), session( nullptr ),
        memoryInfo( Ort::MemoryInfo::CreateCpu( OrtArenaAllocator, OrtMemTypeDefault ) )
    {
        sessionOptions.SetIntraOpNumThreads( 1 );
        sessionOptions.SetGraphOptimizationLevel( GraphOptimizationLevel::ORT_ENABLE_EXTENDED );
        session = Ort::Session( env, modelPath.c_str(), sessionOptions );

        // Ensure input dimensions match
        auto inputTypeInfo   = session.GetInputTypeInfo( 0 );
        auto inputTensorInfo = inputTypeInfo.GetTensorTypeAndShapeInfo();
        auto inputDims       = inputTensorInfo.GetShape();
        if ( std::vector< int64_t >( inputShape.begin(), inputShape.end() ) != inputDims )
        {
            throw std::runtime_error( "Input shape mismatch." );
        }

        // Ensure output dimensions match
        auto outputTypeInfo   = session.GetOutputTypeInfo( 0 );
        auto outputTensorInfo = outputTypeInfo.GetTensorTypeAndShapeInfo();
        auto outputDims       = outputTensorInfo.GetShape();
        if ( std::vector< int64_t >( outputShape.begin(), outputShape.end() ) != outputDims )
        {
            throw std::runtime_error( "Output shape mismatch." );
        }
    }

    void predict()
    {
        std::vector< const char * > inputNames{ "input" };
        std::vector< const char * > outputNames{ "output" };

        Ort::Value inputTensor = Ort::Value::CreateTensor< float >(
            memoryInfo,
            input.data(),
            input.size(),
            inputShape.data(),
            inputShape.size() );
        Ort::Value outputTensor = Ort::Value::CreateTensor< float >(
            memoryInfo,
            output.data(),
            output.size(),
            outputShape.data(),
            outputShape.size() );

        session.Run(
            Ort::RunOptions{ nullptr },
            inputNames.data(),
            &inputTensor,
            1,
            outputNames.data(),
            &outputTensor,
            1 );
    }
};

#endif  // ONNX_MNIST_PREDICTION_PROVIDER_HPP