#include "UniquePtr.hpp"

#include <gtest/gtest.h>

TEST( UniquePtrTest, ConstructorWithValue )
{
    UniquePtr ptr( 1 );
    ASSERT_TRUE( ptr );
    EXPECT_EQ( *ptr, 1 );
}

TEST( UniquePtrTest, MoveConstructor )
{
    UniquePtr ptr1( 1 );
    UniquePtr ptr2( std::move( ptr1 ) );
    ASSERT_FALSE( ptr1 );
    ASSERT_TRUE( ptr2 );
    EXPECT_EQ( *ptr2, 1 );
}

TEST( UniquePtrTest, MoveAssignment )
{
    UniquePtr ptr1( 1 );
    UniquePtr ptr2( 2 );
    ptr2 = std::move( ptr1 );
    ASSERT_FALSE( ptr1 );
    ASSERT_TRUE( ptr2 );
    EXPECT_EQ( *ptr2, 1 );
}

TEST( UniquePtrTest, Reset )
{
    UniquePtr ptr( 1 );
    ptr.reset( 2 );
    ASSERT_TRUE( ptr );
    EXPECT_EQ( *ptr, 2 );
}

TEST( UniquePtrTest, Release )
{
    UniquePtr ptr( 1 );
    int *     rawPtr = ptr.release();
    EXPECT_EQ( ptr.get(), nullptr );
    ASSERT_TRUE( rawPtr );
    EXPECT_EQ( *rawPtr, 1 );
    delete rawPtr;
}