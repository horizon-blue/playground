// Exercise 7.3
// Revise your transaction-processing program from
// Section 7.1.1 (p.256) to use these members
// Xiaoyan Wang 3/7/2016
#include <iostream>
#include <string>
// include the Sales_data class from previous exercise
#include "7.2.cpp"
using namespace std;

// The transaction-processing program
// Mostly copied from 7.1.cpp with some modifications
// (requrement for 7.3 and corrections in program
// logic that I've misunderstood)
int main() {
  // variable to hold data for the next transaction
  Sales_data total;
  unsigned units;
  double price;
  // read the first transaction and ensure that there are
  // data to process
  if (cin >> total.bookNo >> units >> price) {
    total.units_sold += units;
    total.revenue += units * price;
    // variable to hold the running sum
    Sales_data trans;
    unsigned trans_units;
    double trans_price; 
    while (cin >> trans.bookNo >> trans_units >> trans_price) {
      trans.units_sold = trans_units;
      trans.revenue = trans_units * trans_price;
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
	// update the running total
	total.combine(trans);
      }
      else {
	// print results for the previous book
	cout << total.isbn() << ' ' << total.units_sold
	     << ' ' << total.revenue << ' '
	     << total.revenue/total.units_sold << endl;
	// Total now refers to the next book
	total = trans;
      }
    }
    // print the last transaction
    cout << total.isbn() << ' ' << total.units_sold
	 << ' ' << total.revenue << ' '
	 << total.revenue/total.units_sold << endl;
  }
  else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1; // indicate failure
  }
  return 0;
}
