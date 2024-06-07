#ifndef STRING_HPP
#define STRING_HPP

#include <string>

namespace String
{
[[nodiscard]] std::string toLowerCase( std::string input ) noexcept;
[[nodiscard]] std::string toUpperCase( std::string input ) noexcept;
}  // namespace String

#endif