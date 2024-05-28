//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#include "LinkedList.hpp"
#include <stdio.h>
#include <iostream>

LinkedList::LinkedList(){
    std::cout << "Constructor called for LinkedList " << this << std::endl;
}

LinkedList::~LinkedList(){
    while (head_) {
        Node* temp = head_;
        head_ = (*head_).next; // ovo se moze koristit umjesto ->
        delete temp;
    }
    std::cout << "Destructor called for " << this << std::endl;
}

LinkedList::LinkedList(const LinkedList& other) : head_(nullptr), size_(other.size_) {
    if (other.head_) {
        head_ = new Node{other.head_->value};
        Node* current = head_;
        Node* next = other.head_->next;
        while (next) {
            current->next = new Node{next->value};
            current = current->next;
            next = next->next;
        }
    }
    else{
        std::cout << "List to be copied is empty!" << std::endl;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        LinkedList temp(other);
        std::swap(head_, temp.head_);
        std::swap(size_, temp.size_);
    }
    
    return *this;
}

std::size_t LinkedList::size() const {
    return size_;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node{value};
    if (!head_) {
        head_ = newNode;
    } else {
        Node* current = head_;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    ++size_;
}

void LinkedList::erase_first(int value) {
    if (!head_) return;
    
    if (head_->value == value) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        --size_;
        
        return;
    }

    Node* current = head_;
    while (current->next && current->next->value != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        --size_;
    }
}

int LinkedList::get(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range!");
    }
    
    Node* current = head_;
    for (std::size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->value;
}

void LinkedList::print() const {
    Node* current = head_;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

