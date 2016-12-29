// Exercise 13.22
// Write the HasPtr copy constructor and copy-assignment operator before reading
// on
// Xiaoyan Wang 12/28/2016
// written based on 13.05.cpp
#include <string>
class HasPtr {
public:
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    ~HasPtr() { delete ps; }

    // copy assignment operator
    HasPtr& operator=(const HasPtr& other);


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

// testing
int main() {
    HasPtr hp1("Testing");
    HasPtr hp2 = hp1;
    HasPtr hp3("yooo");
    hp2 = hp3;
    return 0;
}