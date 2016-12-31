// Exercise 13.39
// Write your own version of StrVec, including versions of reserve, capacity,
// and resize
// Xiaoyan Wang 12/30/2016
#include "13.39.h"

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements     = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    if(this == &rhs)
        return *this;

    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements   = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::push_back(const string &s) {
    chk_n_alloc();  // ensure that there is room for another element
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n) {
    if(n < capacity())
        return;
    auto newdata = alloc.allocate(n);
    // move the data from the olde memory to the new
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    // update our data structure to point to the new elements
    elements   = newdata;
    first_free = dest;
    cap        = elements + n;
}

void StrVec::resize(size_t n) {
    if(n > size()) {
        if(n < capacity())
            reserve(n);
        for(auto iter = first_free; iter - elements != n; ++iter)
            alloc.construct(iter);  // using default constructor
    } else {
        for(auto iter = first_free; iter - elements != n)
            alloc.destroy(--iter);
    }
    first_free = elements + n;
}

inline void StrVec::chk_n_alloc() {
    if(size() == capacity())
        reallocate();
}

inline std::pair<std::string *, std::string *> alloc_n_copy(
    const std::string *, const std::string *) {
    // allocate space to hold as many elements as in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair constructed from data and the value returned
    // by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

inline void StrVec::free() {
    if(!elements)
        return;
    // destroy the old element in reverse order
    for(auto p = first_free; p != elements;)
        alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // move the data from the olde memory to the new
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    // update our data structure to point to the new elements
    elements   = newdata;
    first_free = dest;
    cap        = elements + newcapacity;
}