#include "ImageLoader.hpp"

#include <fstream>

ImageLoader::ImageLoader( const std::string & path ) :
    ctx( spng_ctx_new( 0 ) ), image_data( nullptr ), width( 0 ), height( 0 )
{
    if ( !ctx )
    {
        throw std::runtime_error( "Failed to create spng context" );
    }
    load( path );
    checkProperties();
}

ImageLoader::~ImageLoader()
{
    if ( ctx )
    {
        spng_ctx_free( ctx );
    }
    if ( image_data )
    {
        free( image_data );
    }
}

ImageLoader::ImageLoader( const ImageLoader & other ) :
    ctx( spng_ctx_new( 0 ) ), image_data( nullptr ), width( other.width ), height( other.height )
{
    if ( !ctx )
    {
        throw std::runtime_error( "Failed to create spng context" );
    }

    size_t image_size = width * height * 4;
    image_data        = ( unsigned char * ) malloc( image_size );
    if ( !image_data )
    {
        spng_ctx_free( ctx );
        throw std::runtime_error( "Failed to allocate memory for image" );
    }

    std::memcpy( image_data, other.image_data, image_size );
}

unsigned char * ImageLoader::getData() const
{
    return image_data;
}

int ImageLoader::getWidth() const
{
    return width;
}

int ImageLoader::getHeight() const
{
    return height;
}

void ImageLoader::load( const std::string & path )
{
    FILE * file = fopen( path.c_str(), "rb" );
    if ( !file )
    {
        throw std::runtime_error( "Failed to open file: " + path );
    }

    spng_set_png_file( ctx, file );

    spng_ihdr ihdr;
    if ( spng_get_ihdr( ctx, &ihdr ) )
    {
        fclose( file );
        throw std::runtime_error( "Failed to get image header" );
    }

    width  = ihdr.width;
    height = ihdr.height;

    size_t image_size;
    if ( spng_decoded_image_size( ctx, SPNG_FMT_RGBA8, &image_size ) )
    {
        fclose( file );
        throw std::runtime_error( "Failed to get decoded image size" );
    }

    image_data = ( unsigned char * ) malloc( image_size );
    if ( !image_data )
    {
        fclose( file );
        throw std::runtime_error( "Failed to allocate memory for image" );
    }

    if ( spng_decode_image( ctx, image_data, image_size, SPNG_FMT_RGBA8, 0 ) )
    {
        fclose( file );
        throw std::runtime_error( "Failed to decode image" );
    }

    fclose( file );
}

void ImageLoader::checkProperties()
{
    if ( width != 28 || height != 28 )
    {
        throw std::runtime_error( "Image is not 28x28 pixels" );
    }

    for ( int i = 0; i < width * height * 4; i += 4 )
    {
        if ( image_data[ i ] != image_data[ i + 1 ] || image_data[ i ] != image_data[ i + 2 ] )
        {
            throw std::runtime_error( "Image is not black and white" );
        }
    }
}