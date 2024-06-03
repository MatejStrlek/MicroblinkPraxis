#include "UniquePtr.hpp"

UniquePtr::UniquePtr( int * ptr ) : ptr_( ptr ) {}

UniquePtr::~UniquePtr()
{
    delete ptr_;
}

UniquePtr::UniquePtr( UniquePtr && other ) noexcept : ptr_( other.ptr_ )
{
    other.ptr_ = nullptr;
}

UniquePtr & UniquePtr::operator=( UniquePtr && other ) noexcept
{
    if ( this != &other )
    {
        delete ptr_;
        ptr_       = other.ptr_;
        other.ptr_ = nullptr;
    }
    return *this;
}

int * UniquePtr::get() const noexcept
{
    return ptr_;
}

int * UniquePtr::release() noexcept
{
    int * temp = ptr_;
    ptr_       = nullptr;
    return temp;
}

void UniquePtr::reset( int * ptr ) noexcept
{
    delete ptr_;
    ptr_ = ptr;
}

int & UniquePtr::operator*() const noexcept
{
    return *ptr_;
}

int * UniquePtr::operator->() const noexcept
{
    return ptr_;
}

UniquePtr::operator bool() const noexcept
{
    return ptr_ != nullptr;
}