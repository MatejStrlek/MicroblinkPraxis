#ifndef IMAGELOADER_HPP
#define IMAGELOADER_HPP

#include <spng.h>
#include <stdexcept>
#include <string>

class ImageLoader
{
public:
    explicit ImageLoader( const std::string & path );
    ~ImageLoader();

    ImageLoader( const ImageLoader & other );

    [[nodiscard]] unsigned char * getData() const;
    [[nodiscard]] int             getWidth() const;
    [[nodiscard]] int             getHeight() const;

private:
    void load( const std::string & path );
    void checkProperties();

    spng_ctx *      ctx;
    unsigned char * image_data;
    int             width;
    int             height;
};

#endif  // IMAGELOADER_HPP
