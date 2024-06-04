//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#include "LinkedList.hpp"

#include <iostream>

LinkedList::LinkedList() {}

LinkedList::~LinkedList()
{
    while ( head_ )
    {
        Node * temp = head_;
        head_       = ( *head_ ).next;
        delete temp;
    }
}

LinkedList::LinkedList( const LinkedList & other ) : head_( nullptr ), size_( other.size_ )
{
    if ( other.head_ )
    {
        head_          = new Node{ other.head_->value };
        Node * current = head_;
        Node * next    = other.head_->next;
        while ( next )
        {
            current->next = new Node{ next->value };
            current       = current->next;
            next          = next->next;
        }
    }
}

LinkedList & LinkedList::operator=( const LinkedList & other )
{
    if ( this != &other )
    {
        LinkedList temp( other );
        std::swap( head_, temp.head_ );
        std::swap( size_, temp.size_ );
    }

    return *this;
}

LinkedList::LinkedList( LinkedList && other ) noexcept : head_( other.head_ ), size_( other.size_ )
{
    other.head_ = nullptr;
    other.size_ = 0;
}

LinkedList & LinkedList::operator=( LinkedList && other ) noexcept
{
    if ( this != &other )
    {
        LinkedList temp( std::move( other ) );
        std::swap( head_, temp.head_ );
        std::swap( size_, temp.size_ );
    }
    return *this;
}

[[nodiscard]] std::size_t LinkedList::size() const noexcept
{
    return size_;
}

void LinkedList::push_back( int value )
{
    Node * newNode = new Node{ value };
    if ( !head_ )
    {
        head_ = newNode;
    }
    else
    {
        Node * current = head_;
        while ( current->next )
        {
            current = current->next;
        }
        current->next = newNode;
    }

    ++size_;
}

void LinkedList::erase_first( int value ) noexcept
{
    if ( !head_ )
        return;

    if ( head_->value == value )
    {
        Node * temp = head_;
        head_       = head_->next;
        delete temp;
        --size_;

        return;
    }

    Node * current = head_;
    while ( current->next && current->next->value != value )
    {
        current = current->next;
    }

    if ( current->next )
    {
        Node * temp   = current->next;
        current->next = current->next->next;
        delete temp;
        --size_;
    }
}

[[nodiscard]] int LinkedList::get( std::size_t index ) const
{
    if ( index >= size_ )
    {
        throw std::out_of_range( "Index out of range" );
    }

    Node * current = head_;
    for ( std::size_t i = 0; i < index; ++i )
    {
        current = current->next;
    }
    return current->value;
}

void LinkedList::print() const noexcept
{
    Node * current = head_;
    while ( current )
    {
        current = current->next;
    }
}
