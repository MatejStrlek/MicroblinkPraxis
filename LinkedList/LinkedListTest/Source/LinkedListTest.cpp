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
    LinkedList list;
    EXPECT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, PushBack )
{
    LinkedList list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    EXPECT_EQ( list.size(), 3 );
}

TEST( LinkedListTest, EraseFirst )
{
    LinkedList list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.erase_first( 2 );
    EXPECT_EQ( list.size(), 2 );
}

TEST( LinkedListTest, EraseFirstNotFound )
{
    LinkedList list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.erase_first( 3 );
    EXPECT_EQ( list.size(), 2 );
}

TEST( LinkedListTest, CopyConstructor )
{
    LinkedList list;
    list.push_back( 1 );
    list.push_back( 2 );
    LinkedList copiedList = list;
    EXPECT_EQ( copiedList.size(), 2 );
    EXPECT_EQ( copiedList.get( 0 ), list.get( 0 ) );
    EXPECT_EQ( copiedList.get( 1 ), list.get( 1 ) );
}

TEST( LinkedListTest, MoveConstructor )
{
    LinkedList list1;
    list1.push_back( 1 );
    list1.push_back( 2 );
    list1.push_back( 3 );

    LinkedList list2( std::move( list1 ) );

    EXPECT_EQ( list2.size(), 3 );
    EXPECT_EQ( list2.get( 0 ), 1 );
    EXPECT_EQ( list2.get( 1 ), 2 );
    EXPECT_EQ( list2.get( 2 ), 3 );

    EXPECT_EQ( list1.size(), 0 );
}

TEST( LinkedListTest, MoveAssignmentOperator )
{
    LinkedList list1;
    list1.push_back( 1 );
    list1.push_back( 2 );
    list1.push_back( 3 );

    LinkedList list2;
    list2 = std::move( list1 );

    EXPECT_EQ( list2.size(), 3 );
    EXPECT_EQ( list2.get( 0 ), 1 );
    EXPECT_EQ( list2.get( 1 ), 2 );
    EXPECT_EQ( list2.get( 2 ), 3 );

    EXPECT_EQ( list1.size(), 0 );
}

TEST( LinkedListTest, AssignmentOperator )
{
    LinkedList list1;
    list1.push_back( 1 );
    list1.push_back( 2 );

    LinkedList list2;
    list2 = list1;
    EXPECT_EQ( list2.size(), 2 );
    EXPECT_EQ( list1.get( 0 ), list2.get( 0 ) );
    EXPECT_EQ( list1.get( 1 ), list2.get( 1 ) );
}

TEST( LinkedListTest, GetElements )
{
    LinkedList list;
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
    LinkedList list;
    EXPECT_NO_THROW( list.erase_first( 1 ) );
    EXPECT_EQ( list.size(), 0 );
}

TEST( LinkedListTest, AddAndRemoveThreeElements )
{
    LinkedList list;
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