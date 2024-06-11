#ifndef IMAGELOADER_HPP
#define IMAGELOADER_HPP

#include <filesystem>
#include <spng.h>
#include <stdexcept>
#include <string>

namespace fs = std::filesystem;

class ImageLoader
{
public:
    ImageLoader();
    explicit ImageLoader( const std::filesystem::path & path );
    ~ImageLoader();

    ImageLoader( const ImageLoader & other );
    ImageLoader & operator=( const ImageLoader & other );

    ImageLoader( ImageLoader && other ) noexcept;
    ImageLoader & operator=( ImageLoader && other ) noexcept;

    [[nodiscard]] unsigned char * getData() const;
    [[nodiscard]] int             getWidth() const;
    [[nodiscard]] int             getHeight() const;

private:
    void load( const std::filesystem::path & path );
    void checkProperties();

    spng_ctx *      ctx;
    unsigned char * image_data;
    int             width;
    int             height;
};

#endif  // IMAGELOADER_HPP
