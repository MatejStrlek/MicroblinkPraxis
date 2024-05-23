//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Matej Galić on 21.05.2024..
//

#include "LinkedList.hpp"


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

LinkedList::LinkedList(const LinkedList& other) : head_(nullptr), size_(0) {
    if (other.head_) {
        head_ = new Node(other.head_->value);
        Node* current = head_;
        Node* second = other.head_->next;
        while (second) {
            current->next = new Node(second->value);
            current = current->next;
            second = second->next;
        }
        size_ = other.size_;
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
    Node* newNode = new Node(value);
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

void LinkedList::print() const {
    Node* current = head_;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

