#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

template < typename T >
class UniquePtr
{
public:
    explicit UniquePtr( T value );
    ~UniquePtr();

    UniquePtr( const UniquePtr & )             = delete;
    UniquePtr & operator=( const UniquePtr & ) = delete;

    UniquePtr( UniquePtr && other ) noexcept;
    UniquePtr & operator=( UniquePtr && other ) noexcept;

    [[nodiscard]] T * get() const noexcept;
    [[nodiscard]] T * release() noexcept;
    void              reset( T value ) noexcept;

    T &                    operator*() const noexcept;
    T *                    operator->() const noexcept;
    [[nodiscard]] explicit operator bool() const noexcept;

private:
    T * ptr;
};

template < typename T >
UniquePtr< T >::UniquePtr( T value ) : ptr( new T( value ) )
{}

template < typename T >
UniquePtr< T >::~UniquePtr()
{
    delete ptr;
}

template < typename T >
UniquePtr< T >::UniquePtr( UniquePtr && other ) noexcept : ptr( other.ptr )
{
    other.ptr = nullptr;
}

template < typename T >
UniquePtr< T > & UniquePtr< T >::operator=( UniquePtr && other ) noexcept
{
    if ( this != &other )
    {
        delete ptr;
        ptr       = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template < typename T >
T * UniquePtr< T >::get() const noexcept
{
    return ptr;
}

template < typename T >
T * UniquePtr< T >::release() noexcept
{
    T * temp = ptr;
    ptr      = nullptr;
    return temp;
}

template < typename T >
void UniquePtr< T >::reset( T value ) noexcept
{
    delete ptr;
    ptr = new T( value );
}

template < typename T >
T & UniquePtr< T >::operator*() const noexcept
{
    return *ptr;
}

template < typename T >
T * UniquePtr< T >::operator->() const noexcept
{
    return ptr;
}

template < typename T >
UniquePtr< T >::operator bool() const noexcept
{
    return ptr != nullptr;
}

#endif