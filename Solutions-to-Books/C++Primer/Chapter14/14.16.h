// Exercise 14.16
// Define equality and inequality operators for your String class
// Xiaoyan Wang 08/06/2017
#ifndef __14_16_H__
#define __14_16_H__
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

    size_t size() const { return first_free - elements; }

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

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

#endif