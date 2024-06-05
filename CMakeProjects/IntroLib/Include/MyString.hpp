#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <string>

class MyString
{
public:
    [[nodiscard]] static std::string toLowerCase( std::string input );
    [[nodiscard]] static std::string toUpperCase( std::string input );
};

#endif