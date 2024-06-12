#ifndef IMAGELOADER_HPP
#define IMAGELOADER_HPP

#include <cstddef>
#include <filesystem>
#include <vector>

namespace MnistImageLoader
{
[[nodiscard]] std::vector< std::byte > load_png( std::filesystem::path const & filepath );
}

#endif  // IMAGELOADER_HPP
