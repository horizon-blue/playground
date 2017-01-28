// Exercise 13.58
// Write versions of class Foo with print statements in their sorted
// functions to test your answers to the previous two exercises
// Xiaoyan Wang 01/28/2017
#ifndef __13_58_CPP__
#define __13_58_CPP__

#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::sort;
using std::cout;
using std::endl;

class Foo {

public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() && {
    cout << "&& version" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    cout << "& version - ";
    return Foo(*this).sorted();  // exercise 13.57
}

int main() {
    Foo f;
    f.sorted();
    Foo().sorted();

    return 0;
}


#endif