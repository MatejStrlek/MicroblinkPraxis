#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

class UniquePtr
{
public:
    explicit UniquePtr( int * ptr = nullptr );
    ~UniquePtr();

    UniquePtr( const UniquePtr & )             = delete;
    UniquePtr & operator=( const UniquePtr & ) = delete;

    UniquePtr( UniquePtr && other ) noexcept;
    UniquePtr & operator=( UniquePtr && other ) noexcept;

    int * get() const noexcept;
    int * release() noexcept;
    void  reset( int * ptr = nullptr ) noexcept;

    int &    operator*() const noexcept;
    int *    operator->() const noexcept;
    explicit operator bool() const noexcept;

private:
    int * ptr_;
};

#endif