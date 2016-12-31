// Exercise 13.40
// Add a constructor that takes an initializer_list<string> to your StrVec
// class.
// Written based on 13.39.h
// Xiaoyan Wang 12/30/2016
#ifndef __13_40_H__
#define __13_40_H__
#include <initializer_list>
#include <memory>  // for std::allocator
#include <string>
#include <utility>  // for std::pair

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);  // copy constructor
    StrVec(const std::initializer_list<std::string> &);
    StrVec &operator=(const StrVec &);  // copy assignment operator
    ~StrVec();                          // destructor
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void reserve(size_t);
    void resize(size_t);

private:
    // static member that is used to allocate memory
    static std::allocator<std::string> alloc;
    // used by the functions that add elements to the StrVec
    void chk_n_alloc();
    // utilities used byt the copy constructor, assignment operator, and
    // destructor
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                         const std::string *);
    void free();        // destroy the elements and free the space
    void reallocate();  // get more space and copy existing elements
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
#endif