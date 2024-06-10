//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <cstddef>
#include <functional>

template < typename T >
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    LinkedList( const LinkedList & other );
    LinkedList & operator=( const LinkedList & other );

    LinkedList( LinkedList && other ) noexcept;
    LinkedList & operator=( LinkedList && other ) noexcept;

    [[nodiscard]] std::size_t size() const noexcept;
    void                      push_back( T value );
    void                      erase_first( T value ) noexcept;
    void                      erase_all( std::function< bool( T ) > predicate ) noexcept;

    [[nodiscard]] const T & get( std::size_t index ) const;
    const T &               operator[]( std::size_t index ) const;

    template < typename U >
    friend std::ostream & operator<<( std::ostream & os, const LinkedList< U > & list );

    struct Node
    {
        explicit Node( T value ) : value{ value } {}
        T                       value;
        std::unique_ptr< Node > next{ nullptr };
    };

    std::unique_ptr< Node > head_{ nullptr };
    std::size_t             size_{ 0 };
};

template < typename T >
LinkedList< T >::LinkedList() = default;

template < typename T >
LinkedList< T >::~LinkedList()
{
    while ( head_ )
    {
        head_ = std::move( head_->next );
    }
}

template < typename T >
LinkedList< T >::LinkedList( const LinkedList & other ) : head_( nullptr ), size_{ other.size_ }
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

template < typename T >
LinkedList< T > & LinkedList< T >::operator=( const LinkedList & other )
{
    if ( this != &other )
    {
        LinkedList temp{ other };
        std::swap( head_, temp.head_ );
        std::swap( size_, temp.size_ );
    }

    return *this;
}

template < typename T >
LinkedList< T >::LinkedList( LinkedList && other ) noexcept : head_{ std::move( other.head_ ) }, size_{ other.size_ }
{
    other.size_ = 0;
}

template < typename T >
LinkedList< T > & LinkedList< T >::operator=( LinkedList && other ) noexcept
{
    if ( this != &other )
    {
        LinkedList temp{ std::move( other ) };
        std::swap( head_, temp.head_ );
        std::swap( size_, temp.size_ );
    }
    return *this;
}

template < typename T >
std::size_t LinkedList< T >::size() const noexcept
{
    return size_;
}

template < typename T >
void LinkedList< T >::push_back( T value )
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

template < typename T >
void LinkedList< T >::erase_first( T value ) noexcept
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

template < typename T >
void LinkedList< T >::erase_all( std::function< bool( T ) > predicate ) noexcept
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

template < typename T >
const T & LinkedList< T >::get( std::size_t index ) const
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

template < typename T >
T const & LinkedList< T >::operator[]( std::size_t index ) const
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

template < typename T >
std::ostream & operator<<( std::ostream & os, const LinkedList< T > & list )
{
    typename LinkedList< T >::Node * current = list.head_.get();
    while ( current )
    {
        os << current->value << " ";
        current = current->next.get();
    }
    return os;
}

#endif /* LinkedList_hpp */