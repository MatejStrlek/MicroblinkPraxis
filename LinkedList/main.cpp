//
//  main.cpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(4);
    list.push_back(6);

    std::cout << "List after adding elements: ";
    list.print();
    std::cout << "List size: " << list.size() << std::endl;

    list.erase_first(4);
    std::cout << "Erasing first 4 in list: ";
    list.print();
    std::cout << "List size: " << list.size() << std::endl;

    LinkedList copiedList = list;
    std::cout << "Copied list: ";
    copiedList.print();

    std::cout << "Original list after moving: ";
    list.print();
    
    LinkedList l1;
    LinkedList l2;
    LinkedList l3;

    return 0;
}

