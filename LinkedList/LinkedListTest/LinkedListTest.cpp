//
//  test_LinkedList.cpp
//  LinkedList
//
//  Created by Matej Galić on 28.05.2024..
//

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, Constructor) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListTest, PushBack) {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
}

TEST(LinkedListTest, EraseFirst) {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase_first(2);
    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListTest, EraseFirstNotFound) {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.erase_first(3);
    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListTest, CopyConstructor) {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    LinkedList copiedList = list;
    EXPECT_EQ(copiedList.size(), 2);
}

TEST(LinkedListTest, AssignmentOperator) {
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(2);

    LinkedList list2;
    list2 = list1;
    EXPECT_EQ(list2.size(), 2);
}

TEST(LinkedListTest, GetElements) {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

TEST(LinkedListTest, EraseFirstEmptyList) {
    LinkedList list;
    EXPECT_NO_THROW(list.erase_first(1));
    EXPECT_EQ(list.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
