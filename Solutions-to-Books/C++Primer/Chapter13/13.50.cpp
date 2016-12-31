// Exercise 13.50
// Put print statements in the move operations in your String class and see when
// the copies are avoided
// written based on 13.49.cpp
// Xiaoyan Wang 12/30/2016
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "13.49.h"

using std::uninitialized_copy;
size_t counter      = 0;
size_t move_counter = 0;

std::allocator<char> String::alloc;

String::String(const String& s) {
    ++counter;
    std::cout << '[' << __func__ << ']' << "constructing " << s << '\n';
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const char* b) {
    ++counter;
    std::cout << '[' << __func__ << ']' << "constructing " << b << '\n';
    size_t i;
    for(i = 0; b[i] != '\0'; ++i)
        ;  // find the null terminator
    auto newdata = alloc_n_copy(b, b + i);
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

String::String(String&& s) noexcept : elements(s.elements),
                                      first_free(s.first_free),
                                      cap(s.cap) {
    ++move_counter;
    std::cout << '[' << __func__ << ']' << "moving " << s << '\n';
    s.elements = s.first_free = s.cap = nullptr;
}

String::~String() {
    free();
}

String& String::operator=(const String& rhs) {
    ++counter;
    std::cout << '[' << __func__ << ']' << "copying " << rhs << '\n';
    if(this == &rhs)
        return *this;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

String& String::operator=(const char* b) {
    ++counter;
    std::cout << '[' << __func__ << ']' << "copying " << b << '\n';
    size_t i;
    for(i = 0; b[i] != '\0'; ++i)
        ;  // find the null terminator
    auto data = alloc_n_copy(b, b + i);
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

String& String::operator=(String&& rhs) noexcept {
    ++move_counter;
    std::cout << '[' << __func__ << ']' << "move-assigning " << rhs << '\n';
    if(this == &rhs)
        return *this;
    elements     = rhs.elements;
    first_free   = rhs.first_free;
    cap          = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
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
    using std::vector;

    vector<String> svec;
    for(size_t i = 0; i < 200; ++i) {
        svec.emplace_back("Hello,");
        svec.emplace_back("World!");
    }

    cout << "copied " << counter << " times" << endl;

    cout << "moved " << move_counter << " times" << endl;

    // cout << endl;

    // for(const auto& s : svec)
    //     cout << s << endl;

    return 0;
}