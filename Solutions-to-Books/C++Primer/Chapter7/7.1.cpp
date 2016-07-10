// Exercise 7.1
// Write a version of the transaction-processing program
// from Section 1.6 (p.24) using the Sales_data class you
// defined for the exercise in Section 2.6.1 (p.72)
// Xiaoyan Wang 3/6/2016
#include <iostream>
#include <string>
using namespace std;

// This part is copied from 2.40.cpp in ~/Chapter2/
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
// End of the struct definition (from 2.40.cpp)

// The transaction-processing program
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
      if (total.bookNo == trans.bookNo) {
	// update the running total
	total.units_sold += trans.units_sold;
	total.revenue += trans.revenue;
      }
      else {
	// print results for the previous book
	cout << total.bookNo << ' ' << total.units_sold
	     << ' ' << total.revenue << ' ' << price << endl;
	// Total now refers to the next book
	total = trans;
      }
    }
    // print the last transaction
    cout << total.bookNo << ' ' << total.units_sold
	 << ' ' << total.revenue << ' ' << price << endl;
  }
  else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1; // indicate failure
  }
  return 0;
}
