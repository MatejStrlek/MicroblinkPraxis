#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

class UniquePtr
{
public:
    explicit UniquePtr( int value );
    ~UniquePtr();

    UniquePtr( const UniquePtr & )             = delete;
    UniquePtr & operator=( const UniquePtr & ) = delete;

    UniquePtr( UniquePtr && other ) noexcept;
    UniquePtr & operator=( UniquePtr && other ) noexcept;

    [[nodiscard]] int * get() const noexcept;
    [[nodiscard]] int * release() noexcept;
    void                reset( int value ) noexcept;

    int &                  operator*() const noexcept;
    int *                  operator->() const noexcept;
    [[nodiscard]] explicit operator bool() const noexcept;

private:
    int * ptr_;
};

#endif