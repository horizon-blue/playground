// Exercise 13.31
// Give you class a < operator and define a vector of HasPtrs. Give that vector
// some elements and then sort the vector. Note when swap is called
// Xiaoyan Wang 12/29/2016
// written based on 13.30.cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
public:
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    ~HasPtr() { delete ps; }

    // copy assignment operator
    HasPtr& operator=(const HasPtr& other);

    // NEW: swap function
    friend void swap(HasPtr& lhs, HasPtr& rhs);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);


private:
    std::string* ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& other) {
    if(this == &other)
        return *this;
    i = other.i;
    delete ps;
    ps = new std::string(*other.ps);
    return *this;
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << std::endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

inline bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
    return *lhs.ps < *rhs.ps;
}

// testing
int main() {
    using std::vector;
    using std::sort;
    using std::string;
    vector<HasPtr> hpvec;
    string temp;
    while(std::cin >> temp)
        hpvec.emplace_back(temp);
    // Notice that sort may not call swap if the input size is too small
    sort(hpvec.begin(), hpvec.end());
    return 0;
}