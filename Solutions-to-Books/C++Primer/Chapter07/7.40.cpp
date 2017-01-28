// Exercise 7.40
// Choose one of the following abstractions. Determine what data are needed in
// the class. Provide an appropriate set of constructors. Explain your
// decisions.
// (a) Book; (b) Date; (c) Employee; (d) Vehicle; (e) Object; (f) Tree
// Xiaoyan Wang 01/28/2017

#ifndef __7_40_CPP__
#define __7_40_CPP__

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

private:
    string title;
    double price;
    string isbn;
    string author;
    vector<string> categories;
};
#endif