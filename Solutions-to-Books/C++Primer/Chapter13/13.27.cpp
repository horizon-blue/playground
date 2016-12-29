// Exercise 13.27
// Define your own reference-counted version of HasPtr
// Xiaoyan Wang 12/28/2016
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr &other) : ps(other.ps), i(other.i), use(other.use) {
        ++*use;
    }
    HasPtr &operator=(const HasPtr &other);
    ~HasPtr();

private:
    std::string *ps;

    int i;
    std::size_t *use;
};

HasPtr &HasPtr::operator=(const HasPtr &other) {
    if(this == &other)
        return *this;
    ++*other.use;
    if(!--*use) {
        delete ps;
        delete use;
    }
    ps  = other.ps;
    use = other.use;
    i   = other.i;
    return *this;
}

HasPtr::~HasPtr() {
    if(!--*use) {
        delete ps;
        delete use;
    }
}

int main() {
    // testing
    HasPtr hp1("Hello");
    HasPtr hp2 = hp1;
    HasPtr hp3("yoo");
    hp2 = hp3;
    return 0;
}