//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <cstddef>
#include <iostream>

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    std::size_t size() const;
    void push_back(int value);
    void erase_first(int value);

    void print() const;

private:
    struct Node {
        Node(int val, Node* nxt = nullptr) : next(nxt), value(val) {}
        Node* next;
        int value;
    };

    Node* head_ = nullptr;
    std::size_t size_ = 0;
};

#endif /* LinkedList_hpp */

