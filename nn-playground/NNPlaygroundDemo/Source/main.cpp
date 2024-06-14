#include "ImageLoader.hpp"
#include "OnnxMnistPredictionProvider.hpp"

#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <iostream>

int main( int argc, char ** argv )
{
    if ( argc < 3 )
    {
        std::cerr << "USAGE: " << argv[ 0 ] << " <MODEL> <PNG>...\n";
        return EXIT_FAILURE;
    }

    std::filesystem::path const modelPath{ argv[ 1 ] };
    OnnxMnistPredictionProvider ortMnist{ modelPath };

    std::cout << std::fixed << std::setprecision( 4 );
    for ( int i = 2; i < argc; ++i )
    {
        std::filesystem::path const pngPath{ argv[ i ] };
        auto const                  png{ MnistImageLoader::load_png( pngPath ) };
        std::transform( png.cbegin(), png.cend(), ortMnist.input.begin(), []( std::byte pixel ) noexcept -> float {
            return std::to_integer< std::uint8_t >( pixel ) / 255.0f;
        } );
        ortMnist.predict();
        std::cout << pngPath.c_str() << ": ";
        for ( const auto x : ortMnist.output )
        {
            std::cout << x << ' ';
        }
        std::cout << " (predicted: "
                  << std::distance(
                         ortMnist.output.cbegin(),
                         std::max_element( ortMnist.output.cbegin(), ortMnist.output.cend() ) )
                  << ")\n";
    }
    return 0;
}