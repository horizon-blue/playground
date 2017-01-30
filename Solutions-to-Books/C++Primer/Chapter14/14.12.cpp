// Exercise 14.12
// Define an input operator for the class you used in exercise 7.40 from Section
// 7.5.1. Be sure the operator handles input errors.
// Xiaoyan Wang 01/30/2017

// Written based on 14.08.cpp

#ifndef __14_12_CPP__
#define __14_12_CPP__

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Book {
public:
    Book() = default;
    Book(const string& t, double p) : title(t), price(p) {}
    Book(const string& t,
         const string& a,
         const string& i,
         double p,
         const vector<string>& cvec)
        : title(t), price(p), isbn(i), author(a), categories(cvec) {}
    Book(const Book& other) = default;

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);

private:
    string title;
    double price;
    string isbn;
    string author;
    vector<string> categories;
};

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << b.title << ", " << b.author << ", " << b.price;
    return os;
}

std::istream& operator>>(std::istream& is, Book& b) {
    if(!(is >> b.title >> b.price >> b.isbn >> b.author)) {
        b = Book();
    } else {
        if(b.price < 0) {
            is.setstate(std::istream::failbit);
            b = Book();
        }
    }
    return is;
}

int main() {
    Book b;
    std::cin >> b;
    std::cout << b << std::endl;
    return 0;
}

#endif