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
    void                      push_back( int value );
    void                      erase_first( int value ) noexcept;
    void                      erase_all( std::function< bool( int ) > predicate ) noexcept;

    [[nodiscard]] int get( std::size_t index ) const;
    const int &       operator[]( std::size_t index ) const;

    friend std::ostream & operator<<( std::ostream & os, const LinkedList & list );

private:
    struct Node
    {
        int                     value;
        std::unique_ptr< Node > next = nullptr;

        explicit Node( int value ) : value( value ) {}
    };

    std::unique_ptr< Node > head_ = nullptr;
    std::size_t             size_ = 0;
};

#endif /* LinkedList_hpp */