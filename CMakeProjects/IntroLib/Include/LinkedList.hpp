//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <cstddef>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    LinkedList( const LinkedList & other ) noexcept;
    LinkedList & operator=( const LinkedList & other ) noexcept;

    LinkedList( LinkedList && other ) noexcept;
    LinkedList & operator=( LinkedList && other ) noexcept;

    std::size_t size() const noexcept;
    void        push_back( int value ) noexcept;
    void        erase_first( int value ) noexcept;

    int get( std::size_t index ) const noexcept;

    void print() const noexcept;

private:
    struct Node
    {
        int    value;
        Node * next = nullptr;
    };

    Node *      head_ = nullptr;
    std::size_t size_ = 0;
};

#endif /* LinkedList_hpp */