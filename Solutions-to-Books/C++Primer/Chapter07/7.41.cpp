// Exercise 7.41
// Rewrite your own version of the Sales_data class to use delegating
// constructors. Add a statement to the body of each of the constructors
// that prints a message whenever it is executed. Write declarations to
// construct a Sales_data object in every way possible. Study the output
// until you are certain you understan the order of execution among
// delegating constructors.
// Xiaoyan Wang 3/23/2016

// mostly copied from 7.26.cpp
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
  // nondelegating constructor initializes member from
  // corresponding arguments
  Sales_data(const std::string& s, unsigned cnt, double price):
    bookNo(s), units_sold(cnt), revenue(cnt*price) {
    std::cout << "Sales_data(const std::string& s, "
	      << "unsigned cnt, double price) is being executed."
	      << std::endl;
  }
  
  // remaining constructors all delegate to another constructor
  Sales_data(): Sales_data("", 0, 0) {
    std::cout << "Sales_data() is being executed."
	      << std::endl;
  }
  
  Sales_data(std::string s): Sales_data(s, 0, 0) {
    std::cout << "Sales_data(std::string s) is being executed."
	      << std::endl;
  }
  Sales_data(std::istream& is): Sales_data() {
    std::cout << "Sales_data(std::istream& is) is being executed."
	      << std::endl;
    read(is, *this);
  }
  
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

// test
int main() {
  using std::cout;
  using std::endl;
  // Test is copied from Moophy's C++ Primer Solution repo
  // Link: https://github.com/Mooophy/Cpp-Primer/blob/master/ch07/ex7_41_TEST.cpp
  cout << "1. default way: " << endl;
  cout << "----------------" << endl;
  Sales_data s1;   
    
  cout << "\n2. use std::string as parameter: " << endl;
  cout << "----------------" << endl;
  Sales_data s2("CPP-Primer-5th");
    
  cout << "\n3. complete parameters: " << endl;
  cout << "----------------" << endl;
  Sales_data s3("CPP-Primer-5th", 3, 25.8);
    
  cout << "\n4. use istream as parameter: " << endl;
  cout << "----------------" << endl;
  Sales_data s4(std::cin);
    
  return 0;
}
