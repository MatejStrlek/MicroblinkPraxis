//
//  test_LinkedList.cpp
//  LinkedList
//
//  Created by Matej Galić on 28.05.2024..
//

#include "LinkedList.hpp"

#include <gtest/gtest.h>

TEST( LinkedListTest, Constructor )
{
    LinkedList< int > list;
    EXPECT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, PushBack )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    EXPECT_EQ( list.size(), 3 );
}

TEST( LinkedListTest, EraseFirst )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.erase_first( 2 );
    EXPECT_EQ( list.size(), 2 );
}

TEST( LinkedListTest, EraseAll )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.push_back( 2 );
    list.push_back( 4 );

    ASSERT_TRUE( list.size() == 5 );
    ASSERT_EQ( list.get( 0 ), 1 );
    ASSERT_EQ( list.get( 1 ), 2 );
    ASSERT_EQ( list.get( 2 ), 3 );
    ASSERT_EQ( list.get( 3 ), 2 );
    ASSERT_EQ( list.get( 4 ), 4 );

    list.erase_all( []( int val ) noexcept { return val == 2; } );

    ASSERT_TRUE( list.size() == 3 );
    ASSERT_EQ( list.get( 0 ), 1 );
    ASSERT_EQ( list.get( 1 ), 3 );
    ASSERT_EQ( list.get( 2 ), 4 );
}

TEST( LinkedListTest, EraseAllNotFound )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.push_back( 2 );
    list.push_back( 4 );

    ASSERT_TRUE( list.size() == 5 );
    ASSERT_EQ( list.get( 0 ), 1 );
    ASSERT_EQ( list.get( 1 ), 2 );
    ASSERT_EQ( list.get( 2 ), 3 );
    ASSERT_EQ( list.get( 3 ), 2 );
    ASSERT_EQ( list.get( 4 ), 4 );

    list.erase_all( []( int val ) noexcept { return val == 5; } );

    ASSERT_TRUE( list.size() == 5 );
}

TEST( LinkedListTest, EraseAllEmptyList )
{
    LinkedList< int > list;
    list.erase_all( []( int val ) noexcept { return true; } );
    ASSERT_EQ( list.size(), 0 );
}

TEST( LinedListTest, EraseAllNumbers )
{
    LinkedList< int > list;

    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.push_back( 2 );
    list.push_back( 4 );

    list.erase_all( []( int val ) noexcept { return true; } );

    ASSERT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, EraseFirstNotFound )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.erase_first( 3 );
    EXPECT_EQ( list.size(), 2 );
}

TEST( LinkedListTest, CopyConstructor )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    LinkedList< int > copiedList = list;
    EXPECT_EQ( copiedList.size(), 2 );
    EXPECT_EQ( copiedList.get( 0 ), list.get( 0 ) );
    EXPECT_EQ( copiedList.get( 1 ), list.get( 1 ) );
}

TEST( LinkedListTest, MoveConstructor )
{
    LinkedList< int > list1;
    list1.push_back( 1 );
    list1.push_back( 2 );
    list1.push_back( 3 );

    LinkedList< int > list2( std::move( list1 ) );

    EXPECT_EQ( list2.size(), 3 );
    EXPECT_EQ( list2.get( 0 ), 1 );
    EXPECT_EQ( list2.get( 1 ), 2 );
    EXPECT_EQ( list2.get( 2 ), 3 );
}

TEST( LinkedListTest, MoveAssignmentOperator )
{
    LinkedList< int > list1;
    list1.push_back( 1 );
    list1.push_back( 2 );
    list1.push_back( 3 );

    LinkedList< int > list2;
    list2 = std::move( list1 );

    EXPECT_EQ( list2.size(), 3 );
    EXPECT_EQ( list2.get( 0 ), 1 );
    EXPECT_EQ( list2.get( 1 ), 2 );
    EXPECT_EQ( list2.get( 2 ), 3 );
}

TEST( LinkedListTest, AssignmentOperator )
{
    LinkedList< int > list1;
    list1.push_back( 1 );
    list1.push_back( 2 );

    LinkedList< int > list2;
    list2 = list1;
    EXPECT_EQ( list2.size(), 2 );
    EXPECT_EQ( list1.get( 0 ), list2.get( 0 ) );
    EXPECT_EQ( list1.get( 1 ), list2.get( 1 ) );
}

TEST( LinkedListTest, GetElements )
{
    LinkedList< int > list;
    list.push_back( 10 );
    list.push_back( 20 );
    list.push_back( 30 );

    EXPECT_EQ( list.size(), 3 );
    EXPECT_EQ( list.get( 0 ), 10 );
    EXPECT_EQ( list.get( 1 ), 20 );
    EXPECT_EQ( list.get( 2 ), 30 );
}

TEST( LinkedListTest, EraseFirstEmptyList )
{
    LinkedList< int > list;
    EXPECT_NO_THROW( list.erase_first( 1 ) );
    EXPECT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, AddAndRemoveThreeElements )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );

    EXPECT_EQ( list.size(), 3 );

    list.erase_first( 1 );
    EXPECT_EQ( list.size(), 2 );
    EXPECT_EQ( list.get( 0 ), 2 );
    EXPECT_EQ( list.get( 1 ), 3 );

    list.erase_first( 2 );
    EXPECT_EQ( list.size(), 1 );
    EXPECT_EQ( list.get( 0 ), 3 );

    list.erase_first( 3 );
    EXPECT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, IndexOperator )
{
    LinkedList< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );

    EXPECT_EQ( list[ 0 ], 1 );
    EXPECT_EQ( list[ 1 ], 2 );
    EXPECT_EQ( list[ 2 ], 3 );
}

TEST( LinkedListTest, BraceInitialization )
{
    LinkedList< int >::Node node{ 10 };
    EXPECT_EQ( node.value, 10 );
}