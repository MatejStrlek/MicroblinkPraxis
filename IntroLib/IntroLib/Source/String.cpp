#include "String.hpp"

#include <algorithm>
#include <cctype>

std::string String::toLowerCase( std::string input ) noexcept
{
    std::transform( input.begin(), input.end(), input.begin(), []( unsigned char c ) { return std::tolower( c ); } );
    return input;
}

std::string String::toUpperCase( std::string input ) noexcept
{
    std::transform( input.begin(), input.end(), input.begin(), []( unsigned char c ) { return std::toupper( c ); } );
    return input;
}
