// Exercise 7.11
// Add constructors to your Sales_data class and write a
// program to use each of the constructors
// Xiaoyan Wang 3/7/2016

// mostly copied from 7.6.cpp
#include <string>
#include <iostream>

struct Sales_data {
  // NEW: Constructors
  Sales_data() = default;
  Sales_data(const std::string& s): bookNo(s) {}
  Sales_data(const std::string& s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(n*p) {}
  Sales_data(std::istream&);
  
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

// NEW: Definition of the last constructor
Sales_data::Sales_data(std::istream& is) {
  read(is, *this);
}

int main() {
  Sales_data s1;
  Sales_data s2("123-456-789-X");
  Sales_data s3("987-654-321-X", 2, 12.3);
  std::cout << "Enter the information for Sales_data s4:\n";
  Sales_data s4(std::cin);

  std::cout << "The Sales_data are: \n";
  print(std::cout, s1) << std::endl;
  print(std::cout, s2) << std::endl;
  print(std::cout, s3) << std::endl;
  print(std::cout, s4) << std::endl;

  return 0;
}
