// Exercise 13.49
// Add a move constructor and move-assignment operator to your String class.
// written based on 13.44.h
// Xiaoyan Wang 12/30/2016
#ifndef __13_49_H__
#define __13_49_H__
#include <iostream>
#include <memory>
#include <utility>

class String {
public:
    // default constructor
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const String&);      // copy constructor
    String(const char*);        // construct using c-string
    String(String&&) noexcept;  // move constructor
    ~String();
    String& operator=(const String&);  // copy assignment operator
    String& operator=(const char*);
    String& operator=(String&&) noexcept;  // move assignment operator

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