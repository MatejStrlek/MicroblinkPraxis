#include "MyString.hpp"

#include <algorithm>
#include <cctype>

std::string MyString::toLowerCase( std::string input )
{
    std::transform( input.begin(), input.end(), input.begin(), []( unsigned char c ) { return std::tolower( c ); } );
    return input;
}

std::string MyString::toUpperCase( std::string input )
{
    std::transform( input.begin(), input.end(), input.begin(), []( unsigned char c ) { return std::toupper( c ); } );
    return input;
}
