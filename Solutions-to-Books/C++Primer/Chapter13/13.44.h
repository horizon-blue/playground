// Exercise 13.44
// Write a class named String that is a simplified version of the library string
// class. Your class should have at least a default constructor and a
// constructor that takes a pointer to a C-style string. Use an allocator to
// allocate memory that your String class uses.
// Xiaoyan Wang 12/30/2016
#ifndef __13_44_H__
#define __13_44_H__
#include <iostream>
#include <memory>
#include <utility>

class String {
public:
    // default constructor
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const String&);  // copy constructor
    String(const char*);    // construct using c-string
    ~String();
    String& operator=(const String&);  // copy assignment operator
    String& operator=(const char*);

    char* begin() const { return elements; }
    char* end() const { return first_free; }

    void clear();

    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    // static member that is used to allocate memory
    static std::allocator<char> alloc;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    char* elements;
    char* first_free;
    char* cap;
};

#endif