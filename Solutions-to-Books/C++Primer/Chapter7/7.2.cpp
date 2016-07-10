// Exercise 7.2
// Add the combine and isbn members to the Sales_data
// class you wrote for the exercise in Section 2.6.2 (P.76)
// Xiaoyan Wang 3/6/2016
#include <string>

struct Sales_data {
  // new member function: combine, isbn
  Sales_data& combine (const Sales_data&);
  std::string isbn () const { return bookNo; }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
