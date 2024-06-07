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

    [[nodiscard]] T get( std::size_t index ) const;
    const T &       operator[]( std::size_t index ) const;

    template < typename U >
    friend std::ostream & operator<<( std::ostream & os, const LinkedList< U > & list );

    struct Node
    {
        T                       value;
        std::unique_ptr< Node > next{ nullptr };

        explicit Node( T value ) : value( value ) {}
    };

private:
    std::unique_ptr< Node > head_ = nullptr;
    std::size_t             size_ = 0;
};

#endif /* LinkedList_hpp */