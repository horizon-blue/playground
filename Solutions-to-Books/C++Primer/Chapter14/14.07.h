// Exercise 14.07
// Define an output operator for your String class you wrote for the exercise in
// Section 13.5
// Xiaoyan Wang 01/28/2017
// I already have this implemented.. so I just copy 13.44.cpp over here
#ifndef __14_07_H__
#define __14_07_H__
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