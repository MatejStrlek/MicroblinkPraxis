#include "ImageLoader.hpp"

#include <iostream>
#include <spng.h>
#include <stdexcept>

namespace MnistImageLoader
{
[[nodiscard]] std::vector< std::byte > load_png( std::filesystem::path const & filepath )
{
    spng_ctx * ctx{ spng_ctx_new( 0 ) };
    if ( !ctx )
    {
        throw std::runtime_error{ "Failed to create spng context" };
    }

    FILE * file{ std::fopen( filepath.c_str(), "rb" ) };
    if ( !file )
    {
        spng_ctx_free( ctx );
        throw std::runtime_error{ "Failed to open file: " + filepath.string() };
    }

    spng_set_png_file( ctx, file );

    spng_ihdr ihdr;

    auto err{ spng_get_ihdr( ctx, &ihdr ) };
    if ( err )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ spng_strerror( err ) };
    }

    if ( ihdr.color_type != SPNG_COLOR_TYPE_GRAYSCALE )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ "Image is not grayscale" };
    }

    if ( ihdr.bit_depth != 8 )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ "Image bit depth is not 8" };
    }

    if ( ihdr.width != 28 || ihdr.height != 28 )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ "Image is not 28x28 pixels" };
    }

    size_t image_size;
    err = spng_decoded_image_size( ctx, SPNG_FMT_PNG, &image_size );
    if ( err )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ spng_strerror( err ) };
    }

    std::vector< std::byte > image_data;
    image_data.resize( image_size );
    err = spng_decode_image( ctx, image_data.data(), image_size, SPNG_FMT_PNG, 0 );
    if ( err )
    {
        std::fclose( file );
        spng_ctx_free( ctx );
        throw std::runtime_error{ spng_strerror( err ) };
    }

    std::fclose( file );
    spng_ctx_free( ctx );

    return image_data;
}
}  // namespace MnistImageLoader