#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <cstddef>
#include <memory.h>
#include <iostream>

namespace my_vector {

template <typename T>
class my_vector {
public:
    my_vector();
    explicit my_vector(std::size_t n);
    my_vector(const my_vector<T>& other);
    my_vector<T>& operator=(const my_vector<T>& other);
    ~my_vector();

    std::size_t size() const;
    std::size_t capacity() const;
    bool empty() const;
	
    void resize(std::size_t n);
    void reserve(std::size_t n);
	
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
	
    void push_back(const T& t);
    void pop_back();
    void clear();

private:
    void array_copy(T*& dest) const;
    void free();
    std::size_t new_capacity(std::size_t n) const;
    void init_default(std::size_t l, std::size_t r);
    void pop_under(std::size_t lsize);
	
private:
    size_t capacity_;
    size_t size_;
    T* array_;
};

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_
