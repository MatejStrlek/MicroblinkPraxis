#include "UniquePtr.hpp"

#include <gtest/gtest.h>

TEST( UniquePtrTest, DefaultConstructor )
{
    UniquePtr ptr;
    EXPECT_EQ( ptr.get(), nullptr );
}

TEST( UniquePtrTest, ConstructorWithPointer )
{
    UniquePtr ptr( new int( 42 ) );
    EXPECT_NE( ptr.get(), nullptr );
    EXPECT_EQ( *ptr, 42 );
}

TEST( UniquePtrTest, MoveConstructor )
{
    UniquePtr ptr1( new int( 42 ) );
    UniquePtr ptr2( std::move( ptr1 ) );
    EXPECT_EQ( ptr1.get(), nullptr );
    EXPECT_NE( ptr2.get(), nullptr );
    EXPECT_EQ( *ptr2, 42 );
}

TEST( UniquePtrTest, MoveAssignment )
{
    UniquePtr ptr1( new int( 42 ) );
    UniquePtr ptr2;
    ptr2 = std::move( ptr1 );
    EXPECT_EQ( ptr1.get(), nullptr );
    EXPECT_NE( ptr2.get(), nullptr );
    EXPECT_EQ( *ptr2, 42 );
}

TEST( UniquePtrTest, Reset )
{
    UniquePtr ptr( new int( 42 ) );
    ptr.reset( new int( 100 ) );
    EXPECT_NE( ptr.get(), nullptr );
    EXPECT_EQ( *ptr, 100 );
}

TEST( UniquePtrTest, Release )
{
    UniquePtr ptr( new int( 42 ) );
    int *     rawPtr = ptr.release();
    EXPECT_EQ( ptr.get(), nullptr );
    EXPECT_NE( rawPtr, nullptr );
    EXPECT_EQ( *rawPtr, 42 );
    delete rawPtr;
}