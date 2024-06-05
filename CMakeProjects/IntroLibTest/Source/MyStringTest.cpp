#include "MyString.hpp"

#include <gtest/gtest.h>

TEST( MyStringTest, ToLowerCaseAllUppercase )
{
    std::string input    = "HELLO, WORLD!";
    std::string expected = "hello, world!";
    EXPECT_EQ( MyString::toLowerCase( input ), expected );
}

TEST( MyStringTest, ToLowerCaseAllLowercase )
{
    std::string input    = "hello, world!";
    std::string expected = "hello, world!";
    EXPECT_EQ( MyString::toLowerCase( input ), expected );
}

TEST( MyStringTest, ToLowerCaseWithNumbersAndPunctuation )
{
    std::string input    = "Hello, World! 12345.";
    std::string expected = "hello, world! 12345.";
    EXPECT_EQ( MyString::toLowerCase( input ), expected );
}

TEST( MyStringTest, ToLowerCaseEmptyString )
{
    std::string input    = "";
    std::string expected = "";
    EXPECT_EQ( MyString::toLowerCase( input ), expected );
}

TEST( MyStringTest, ToUpperCaseAllLowercase )
{
    std::string input    = "hello, world!";
    std::string expected = "HELLO, WORLD!";
    EXPECT_EQ( MyString::toUpperCase( input ), expected );
}

TEST( StringTest, ToUpperCaseAllUppercase )
{
    std::string input    = "HELLO, WORLD!";
    std::string expected = "HELLO, WORLD!";
    EXPECT_EQ( MyString::toUpperCase( input ), expected );
}

TEST( MyStringTest, ToUpperCaseWithNumbersAndPunctuation )
{
    std::string input    = "Hello, World! 12345.";
    std::string expected = "HELLO, WORLD! 12345.";
    EXPECT_EQ( MyString::toUpperCase( input ), expected );
}

TEST( MyStringTest, ToUpperCaseEmptyString )
{
    std::string input    = "";
    std::string expected = "";
    EXPECT_EQ( MyString::toUpperCase( input ), expected );
}