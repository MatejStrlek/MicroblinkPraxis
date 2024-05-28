//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#ifndef LinkedList_hpp
#define LinkedList_hpp


#include <cstddef>

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    std::size_t size() const;
    void push_back(int value);
    void erase_first(int value);

    int get(std::size_t index) const;

    void print() const;

private:
    struct Node {
        int value;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    std::size_t size_ = 0;
};

#endif /* LinkedList_hpp */

