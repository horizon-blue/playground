// Exercise 14.08
// Define an outout operator for the class you chose in exercise 7.40
// Xiaoyan Wang 01/28/2017

// Written based on 7.40.cpp

#ifndef __14_08_CPP__
#define __14_08_CPP__

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

private:
    string title;
    double price;
    string isbn;
    string author;
    vector<string> categories;
};

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << b.title << ", " << p.author << ", " << p.price;
    return os;
}

#endif