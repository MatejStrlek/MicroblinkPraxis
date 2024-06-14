#include "ImageLoader.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

const std::filesystem::path testDataDir = "../test-data";

TEST( ImageLoaderTest, BlackAndWhite28x28 )
{
    ASSERT_NO_THROW( {
        auto image_data{ MnistImageLoader::load_png( testDataDir / "train58.png" ) };
        image_data.resize( 28 * 28 * sizeof( std::byte ) );
        EXPECT_EQ( image_data.size(), 28 * 28 * sizeof( std::byte ) );
    } );
}

TEST( ImageLoaderTest, BlackAndWhiteNot28x28 )
{
    ASSERT_THROW(
        { auto image_data{ MnistImageLoader::load_png( testDataDir / "black_white_not_28px.png" ) }; },
        std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhite28x28 )
{
    ASSERT_THROW(
        { auto image_data{ MnistImageLoader::load_png( testDataDir / "not_black_white.png" ) }; },
        std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhiteNot28x28 )
{
    ASSERT_THROW(
        { auto image_data{ MnistImageLoader::load_png( testDataDir / "not_black_white_not_28px.png" ) }; },
        std::runtime_error );
}

TEST( ImageLoaderTest, InvalidPath )
{
    ASSERT_THROW(
        { auto image_data{ MnistImageLoader::load_png( testDataDir / "invalid.png" ) }; },
        std::runtime_error );
}