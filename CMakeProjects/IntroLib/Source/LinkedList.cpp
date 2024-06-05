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
        head_ = std::move( head_->next );
    }
}

LinkedList::LinkedList( const LinkedList & other ) : head_( nullptr ), size_( other.size_ )
{
    if ( other.head_ )
    {
        head_               = std::make_unique< Node >( other.head_->value );
        Node * current      = head_.get();
        Node * otherCurrent = other.head_->next.get();
        while ( otherCurrent )
        {
            current->next = std::make_unique< Node >( otherCurrent->value );
            current       = current->next.get();
            otherCurrent  = otherCurrent->next.get();
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

LinkedList::LinkedList( LinkedList && other ) noexcept : head_( std::move( other.head_ ) ), size_( other.size_ )
{
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

std::size_t LinkedList::size() const noexcept
{
    return size_;
}

void LinkedList::push_back( int value )
{
    auto newNode = std::make_unique< Node >( value );
    if ( !head_ )
    {
        head_ = std::move( newNode );
    }
    else
    {
        Node * current = head_.get();
        while ( current->next )
        {
            current = current->next.get();
        }
        current->next = std::move( newNode );
    }
    ++size_;
}

void LinkedList::erase_first( int value ) noexcept
{
    if ( !head_ )
        return;

    if ( head_->value == value )
    {
        head_ = std::move( head_->next );
        --size_;
        return;
    }

    Node * current = head_.get();
    while ( current->next && current->next->value != value )
    {
        current = current->next.get();
    }

    if ( current->next )
    {
        current->next = std::move( current->next->next );
        --size_;
    }
}

void LinkedList::erase_all( std::function< bool( int ) > predicate ) noexcept
{
    if ( !head_ )
        return;

    while ( head_ && predicate( head_->value ) )
    {
        head_ = std::move( head_->next );
        --size_;
    }

    Node * current = head_.get();
    while ( current && current->next )
    {
        if ( predicate( current->next->value ) )
        {
            current->next = std::move( current->next->next );
            --size_;
        }
        else
        {
            current = current->next.get();
        }
    }
}

int LinkedList::get( std::size_t index ) const
{
    if ( index >= size_ )
    {
        throw std::out_of_range( "Index out of range" );
    }

    Node * current = head_.get();
    for ( std::size_t i = 0; i < index; ++i )
    {
        current = current->next.get();
    }
    return current->value;
}

int const & LinkedList::operator[]( std::size_t index ) const
{
    if ( index >= size_ )
    {
        throw std::out_of_range( "Index out of range" );
    }

    Node * current = head_.get();
    for ( std::size_t i = 0; i < index; ++i )
    {
        current = current->next.get();
    }
    return current->value;
}

std::ostream & operator<<( std::ostream & os, const LinkedList & list )
{
    LinkedList::Node * current = list.head_.get();
    while ( current )
    {
        os << current->value << " ";
        current = current->next.get();
    }
    return os;
}