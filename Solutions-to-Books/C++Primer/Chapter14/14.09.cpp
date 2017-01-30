// Exercise 14.09
// Define an input operator for your Sales_data class

// Xiaoyan Wang 01/30/2017
// Written based on 14.06.cpp
#include <iostream>
#include <string>

class Sales_data;
std::ostream& print(std::ostream& os, const Sales_data&);
Sales_data add(const Sales_data& lhs, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

class Sales_data {
    friend std::ostream& print(std::ostream& os, const Sales_data&);
    friend Sales_data add(const Sales_data& lhs, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);

public:
    Sales_data() : units_sold(0), revenue(0) {}
    Sales_data(const std::string& s) : bookNo(s) {}
    Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream& is) { read(is, *this); }

    Sales_data& combine(const Sales_data&);
    std::string isbn() const { return bookNo; }

    // operators
    Sales_data& operator+=(const Sales_data& other);

private:
    // NEW: avg_price() as an inline function
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue      = 0.0;
};

// other non-member operators
std::ostream& operator<<(std::ostream& os, const Sales_data& sd) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
       << item.avg_price();
    return os;
}

std::istream& operator>>(std::istream& is, Sales_data& sd) {
    double price = 0;
    if(is >> item.bookNo >> item.units_sold >> price)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

Sales_data& operator+(Sales_data& lhs, Sales_data& rhs);

// NEW: avg_price() as an inline function
inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
       << item.avg_price();
    return os;
}
