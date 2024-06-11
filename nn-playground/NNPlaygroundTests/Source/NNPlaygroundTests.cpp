#include "ImageLoader.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

namespace fs = std::filesystem;

const fs::path testDataDir = "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data";

TEST( ImageLoaderTest, BlackAndWhite28x28 )
{
    ASSERT_NO_THROW( {
        ImageLoader loader( testDataDir / "valid.png" );
        EXPECT_EQ( loader.getWidth(), 28 );
        EXPECT_EQ( loader.getHeight(), 28 );

        ImageLoader loaderCopy( loader );
        EXPECT_EQ( loaderCopy.getWidth(), 28 );
        EXPECT_EQ( loaderCopy.getHeight(), 28 );
    } );
}

TEST( ImageLoaderTest, BlackAndWhiteNot28x28 )
{
    ASSERT_THROW( { ImageLoader loader( testDataDir / "black_white_not_28px.png" ); }, std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhite28x28 )
{
    ASSERT_THROW( { ImageLoader loader( testDataDir / "not_black_white.png" ); }, std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhiteNot28x28 )
{
    ASSERT_THROW( { ImageLoader loader( testDataDir / "not_black_white_not_28px.png" ); }, std::runtime_error );
}

TEST( ImageLoaderTest, InvalidPath )
{
    ASSERT_THROW( { ImageLoader loader( testDataDir / "invalid.png" ); }, std::runtime_error );
}

TEST( ImageLoaderTest, CopyConstructor )
{
    ASSERT_NO_THROW( {
        ImageLoader loader( testDataDir / "valid.png" );
        ImageLoader loaderCopy( loader );
        EXPECT_EQ( loaderCopy.getWidth(), 28 );
        EXPECT_EQ( loaderCopy.getHeight(), 28 );
    } );
}

TEST( ImageLoaderTest, CopyAssignment )
{
    ImageLoader loader( testDataDir / "valid.png" );
    ImageLoader loaderCopy;
    loaderCopy = loader;

    ASSERT_EQ( loaderCopy.getWidth(), 28 );
    ASSERT_EQ( loaderCopy.getHeight(), 28 );
    ASSERT_NE( loaderCopy.getData(), nullptr );
}

TEST( ImageLoaderTest, MoveConstructor )
{
    ASSERT_NO_THROW( {
        ImageLoader loader( testDataDir / "valid.png" );
        ImageLoader loaderMoved( std::move( loader ) );
        ASSERT_EQ( loaderMoved.getWidth(), 28 );
        ASSERT_EQ( loaderMoved.getHeight(), 28 );
    } );
}

TEST( ImageLoaderTest, MoveAssignment )
{
    ImageLoader loader( testDataDir / "valid.png" );
    ImageLoader loaderMoved;
    loaderMoved = std::move( loader );

    ASSERT_EQ( loaderMoved.getWidth(), 28 );
    ASSERT_EQ( loaderMoved.getHeight(), 28 );
    ASSERT_NE( loaderMoved.getData(), nullptr );
    ASSERT_EQ( loader.getData(), nullptr );
}