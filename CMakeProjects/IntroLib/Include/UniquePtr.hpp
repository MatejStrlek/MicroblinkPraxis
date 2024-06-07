#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

template < typename T >
class UniquePtr
{
public:
    explicit UniquePtr( T ptr_ );
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
    T * ptr_;
};

#endif