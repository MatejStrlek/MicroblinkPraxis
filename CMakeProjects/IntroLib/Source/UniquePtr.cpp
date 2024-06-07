#include "UniquePtr.hpp"

template < typename T >
UniquePtr< T >::UniquePtr( T value ) : ptr_( new T( value ) )
{}

template < typename T >
UniquePtr< T >::~UniquePtr()
{
    delete ptr_;
}

template < typename T >
UniquePtr< T >::UniquePtr( UniquePtr && other ) noexcept : ptr_( other.ptr_ )
{
    other.ptr_ = nullptr;
}

template < typename T >
UniquePtr< T > & UniquePtr< T >::operator=( UniquePtr && other ) noexcept
{
    if ( this != &other )
    {
        delete ptr_;
        ptr_       = other.ptr_;
        other.ptr_ = nullptr;
    }
    return *this;
}

template < typename T >
T * UniquePtr< T >::get() const noexcept
{
    return ptr_;
}

template < typename T >
T * UniquePtr< T >::release() noexcept
{
    T * temp = ptr_;
    ptr_     = nullptr;
    return temp;
}

template < typename T >
void UniquePtr< T >::reset( T value ) noexcept
{
    delete ptr_;
    ptr_ = new T( value );
}

template < typename T >
T & UniquePtr< T >::operator*() const noexcept
{
    return *ptr_;
}

template < typename T >
T * UniquePtr< T >::operator->() const noexcept
{
    return ptr_;
}

template < typename T >
UniquePtr< T >::operator bool() const noexcept
{
    return ptr_ != nullptr;
}

template class UniquePtr< int >;