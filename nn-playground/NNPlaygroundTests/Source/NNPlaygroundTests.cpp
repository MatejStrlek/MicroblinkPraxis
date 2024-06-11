#include "ImageLoader.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

TEST( ImageLoaderTest, BlackAndWhite28x28 )
{
    ASSERT_NO_THROW( {
        ImageLoader loader( "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/valid.png" );
        EXPECT_EQ( loader.getWidth(), 28 );
        EXPECT_EQ( loader.getHeight(), 28 );

        ImageLoader loaderCopy( loader );
        EXPECT_EQ( loaderCopy.getWidth(), 28 );
        EXPECT_EQ( loaderCopy.getHeight(), 28 );
    } );
}

TEST( ImageLoaderTest, BlackAndWhiteNot28x28 )
{
    ASSERT_THROW(
        {
            ImageLoader loader(
                "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/black_white_not_28px.png" );
        },
        std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhite28x28 )
{
    ASSERT_THROW(
        {
            ImageLoader loader(
                "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/not_black_white.png" );
        },
        std::runtime_error );
}

TEST( ImageLoaderTest, NotBlackAndWhiteNot28x28 )
{
    ASSERT_THROW(
        {
            ImageLoader loader(
                "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/not_black_white_not_28px.png" );
        },
        std::runtime_error );
}

TEST( ImageLoaderTest, InvalidPath )
{
    ASSERT_THROW(
        { ImageLoader loader( "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/invalid.png" ); },
        std::runtime_error );
}

TEST( ImageLoaderTest, CopyConstructor )
{
    ASSERT_NO_THROW( {
        ImageLoader loader( "/Users/matejgalic/Documents/Praksa/Praxis/nn-playground/test-data/valid.png" );
        ImageLoader loaderCopy( loader );
        EXPECT_EQ( loaderCopy.getWidth(), 28 );
        EXPECT_EQ( loaderCopy.getHeight(), 28 );
    } );
}