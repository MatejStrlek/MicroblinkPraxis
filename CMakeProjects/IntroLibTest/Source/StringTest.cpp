#include "String.hpp"

#include <gtest/gtest.h>

TEST( StringTest, ToLowerCaseAllUppercase )
{
    std::string input    = "HELLO, WORLD!";
    std::string expected = "hello, world!";
    EXPECT_EQ( String::toLowerCase( input ), expected );
}

TEST( StringTest, ToLowerCaseAllLowercase )
{
    std::string input    = "hello, world!";
    std::string expected = "hello, world!";
    EXPECT_EQ( String::toLowerCase( input ), expected );
}

TEST( StringTest, ToLowerCaseWithNumbersAndPunctuation )
{
    std::string input    = "Hello, World! 12345.";
    std::string expected = "hello, world! 12345.";
    EXPECT_EQ( String::toLowerCase( input ), expected );
}

TEST( StringTest, ToLowerCaseEmptyString )
{
    std::string input    = "";
    std::string expected = "";
    EXPECT_EQ( String::toLowerCase( input ), expected );
}

TEST( StringTest, ToUpperCaseAllLowercase )
{
    std::string input    = "hello, world!";
    std::string expected = "HELLO, WORLD!";
    EXPECT_EQ( String::toUpperCase( input ), expected );
}

TEST( StringTest, ToUpperCaseAllUppercase )
{
    std::string input    = "HELLO, WORLD!";
    std::string expected = "HELLO, WORLD!";
    EXPECT_EQ( String::toUpperCase( input ), expected );
}

TEST( StringTest, ToUpperCaseWithNumbersAndPunctuation )
{
    std::string input    = "Hello, World! 12345.";
    std::string expected = "HELLO, WORLD! 12345.";
    EXPECT_EQ( String::toUpperCase( input ), expected );
}

TEST( StringTest, ToUpperCaseEmptyString )
{
    std::string input    = "";
    std::string expected = "";
    EXPECT_EQ( String::toUpperCase( input ), expected );
}