// Exercise 14.07
// Define an output operator for your String class you wrote for the exercise in
// Section 13.5
// Xiaoyan Wang 01/28/2017
// I already have this implemented.. so I just copy 13.44.cpp over here
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
using std::uninitialized_copy;

#include "14.07.h"

std::allocator<char> String::alloc;

String::String(const String& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const char* b) {
    size_t i;
    for(i = 0; b[i] != '\0'; ++i)
        ;  // find the null terminator
    auto newdata = alloc_n_copy(b, b + i);
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

String::~String() {
    free();
}

String& String::operator=(const String& rhs) {
    if(this == &rhs)
        return *this;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

String& String::operator=(const char* b) {
    size_t i;
    for(i = 0; b[i] != '\0'; ++i)
        ;  // find the null terminator
    auto data = alloc_n_copy(b, b + i);
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

void String::clear() {
    free();
    elements = cap = first_free = nullptr;
}

void String::free() {
    if(!elements)
        return;
    // destroy the old element in reverse order
    std::for_each(
        elements, first_free, [this](char& rhs) { alloc.destroy(&rhs); });
    alloc.deallocate(elements, cap - elements);
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}


std::ostream& operator<<(std::ostream& os, const String& s) {
    for(const char& c : s)  // using begin() and end()
        os << c;
    return os;
}

int main() {
    // test
    using std::cout;
    using std::endl;
    String s1("Hello");
    String s2 = s1;
    s1        = "World";
    cout << s2 << ' ' << s1 << '!' << endl;
    return 0;
}