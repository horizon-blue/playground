// Exercise 13.30
// Write and test a swap function for your valuelike version of HasPtr. Give
// your swap a print statement that notes when it is executed
// Xiaoyan Wang 12/29/2016
// written based on 13.22.cpp
#include <iostream>
#include <string>
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

// testing
int main() {
    HasPtr hp1("Testing");
    HasPtr hp2 = hp1;
    HasPtr hp3("yooo");
    hp2 = hp3;
    swap(hp1, hp3);
    swap(hp1, hp2);
    return 0;
}