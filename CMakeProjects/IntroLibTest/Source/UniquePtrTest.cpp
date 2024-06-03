#include "UniquePtr.hpp"

#include <gtest/gtest.h>

TEST( UniquePtrTest, ConstructorWithValue )
{
    UniquePtr ptr( 1 );
    EXPECT_NE( ptr.get(), nullptr );
    EXPECT_EQ( *ptr, 1 );
}

TEST( UniquePtrTest, MoveConstructor )
{
    UniquePtr ptr1( 1 );
    UniquePtr ptr2( std::move( ptr1 ) );
    EXPECT_EQ( ptr1.get(), nullptr );
    EXPECT_NE( ptr2.get(), nullptr );
    EXPECT_EQ( *ptr2, 1 );
}

TEST( UniquePtrTest, MoveAssignment )
{
    UniquePtr ptr1( 1 );
    UniquePtr ptr2( 2 );
    ptr2 = std::move( ptr1 );
    EXPECT_EQ( ptr1.get(), nullptr );
    EXPECT_NE( ptr2.get(), nullptr );
    EXPECT_EQ( *ptr2, 1 );
}

TEST( UniquePtrTest, Reset )
{
    UniquePtr ptr( 1 );
    ptr.reset( 2 );
    EXPECT_NE( ptr.get(), nullptr );
    EXPECT_EQ( *ptr, 2 );
}

TEST( UniquePtrTest, Release )
{
    UniquePtr ptr( 1 );
    int *     rawPtr = ptr.release();
    EXPECT_EQ( ptr.get(), nullptr );
    EXPECT_NE( rawPtr, nullptr );
    EXPECT_EQ( *rawPtr, 1 );
    delete rawPtr;
}