// Exercise 7.6
// Define your own versions of the add, read
// and print functions
// Xiaoyan Wang 3/7/2016
#include <string>
#include <iostream>

struct Sales_data {
  Sales_data& combine (const Sales_data&);
  std::string isbn() const { return bookNo; }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

// New functions: add, read and print
Sales_data add(const Sales_data& lhs,
			   const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

std::istream& read(std::istream &is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream& print (std::ostream& os, const Sales_data& item) {
  os << item.isbn() << ' ' << item.units_sold
     << ' ' << item.revenue << ' '
     << item.revenue/item.units_sold;
  return os;
}
