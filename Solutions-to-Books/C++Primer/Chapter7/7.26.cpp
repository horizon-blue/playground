// Exercise 7.26
// Define Sales_data::avg_price as an inline function.
// Xiaoyan Wang 3/17/2016

// mostly copied from 7.21.cpp
#include <string>
#include <iostream>

class Sales_data;
std::ostream& print (std::ostream& os, const Sales_data&);
Sales_data add(const Sales_data& lhs, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

class Sales_data {
  friend std::ostream& print (std::ostream& os, const Sales_data&);
  friend Sales_data add(const Sales_data& lhs, const Sales_data&);
  friend std::istream& read(std::istream&, Sales_data&);
    
public:
  Sales_data(): units_sold(0), revenue(0) {}
  Sales_data(const std::string& s): bookNo(s) {}
  Sales_data(const std::string& s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(n*p) {}
  Sales_data(std::istream& is) { read(is, *this); }
  
  Sales_data& combine (const Sales_data&);
  std::string isbn() const { return bookNo; }

private:
  // NEW: avg_price() as an inline function
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// NEW: avg_price() as an inline function
inline double Sales_data::avg_price() const{
  return units_sold ? revenue/units_sold : 0;
}

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
     << item.avg_price();
  return os;
}
