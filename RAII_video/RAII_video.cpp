//
//  RAII_video.cpp
//  HelloWorld
//
//  Created by Matej Galić on 20.05.2024..
//

#include <stdio.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>


class NaiveVector{
    int *ptr_;
    size_t size_;
    
public:
    //constructor
    NaiveVector(): ptr_(nullptr), size_(0) {
        std::cout << "Constructor is called!\n";
    }
    
    void push_back(int newValue){
        int *newptr = new int[size_ + 1];
        std::copy(ptr_, ptr_ + size_, newptr);
        delete[] ptr_;
        ptr_ = newptr;
        ptr_[size_++] = newValue;
    }
    
    //copy constructor
    NaiveVector(const NaiveVector& rhs){
        ptr_ = new int[rhs.size_];
        size_ = rhs.size_;
        std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_);
        
        std::cout << "Copy constructor!\n";
    }
    
    void swap(NaiveVector& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(size_, other.size_);
    }
    
    //copy assignment operator
    NaiveVector& operator=(const NaiveVector& rhs){
        NaiveVector copy = rhs;
        copy.swap(*this);
        std::cout << "Copy assignment operator!\n";
        return *this;
    }
    
    //destructor
    ~NaiveVector() {
        std::cout << "Destructor is called!\n";
        delete[] ptr_;
    }
    
    void print() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << ptr_[i] << " ";
        }
        
        std::cout << std::endl;
    }
    
    //move constructor
    NaiveVector(NaiveVector&& rhs){
        ptr_ = std::exchange(rhs.ptr_, nullptr);
        size_ = std::exchange(rhs.size_, 0);
    }
};


struct RAIIPtr{
    int *ptr_;
    RAIIPtr(int *p) : ptr_(p) {}
    ~RAIIPtr() {delete [] ptr_;}
    
    RAIIPtr(const RAIIPtr&) = delete;
    RAIIPtr& operator=(const RAIIPtr&) = delete;
};


int main() {
    NaiveVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    std::cout << "Originalni vec1: ";
    vec1.print();

    NaiveVector vec2 = vec1; // Kopiranje
    std::cout << "Kopirani vec2: ";
    vec2.print();

    NaiveVector vec3 = std::move(vec1); // Premjestanje
    std::cout << "Premjesteni vec3 (iz vec1): ";
    vec3.print();

    std::cout << "Nakon premjestanja, vec1 bi trebao biti prazan: ";
    vec1.print();
    
    NaiveVector w = vec3;
    //w = vec3;
    
    w.print();

    return 0;
}
