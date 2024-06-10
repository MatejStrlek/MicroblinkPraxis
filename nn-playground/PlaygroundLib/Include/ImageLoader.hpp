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

    unsigned char * getData() const;
    int             getWidth() const;
    int             getHeight() const;

private:
    void load( const std::string & path );
    void checkProperties();

    spng_ctx *      ctx;
    unsigned char * image_data;
    int             width;
    int             height;
};

#endif  // IMAGELOADER_HPP
