// Exercise 7.13
// Rewrite the program from page 255 to use the
// istream constructor.
// Xiaoyan Wang 3/7/2016
#include <iostream>
#include <string>
// include the Sales_data class from previous exercise
#include "7.12.cpp"
using namespace std;

// The transaction-processing program
// Mostly copied from 7.7.cpp with some modifications
int main() {
  // variable to hold data for the next transaction
  Sales_data total(cin);
  // read the first transaction and ensure that there are
  // data to process
  if (!total.isbn().empty()) {
    while (cin) {
      // variable to hold the running sum
      Sales_data trans(cin);
      if(!trans.isbn().empty()) {
	// if we're still processing the same book
	if (total.isbn() == trans.isbn()) {
	  // update the running total
	  total.combine(trans);
	}
	else {
	  // print results for the previous book
	  print(cout, total) << endl;
	  // Total now refers to the next book
	  total = trans;
	}
      }
    }
    // print the last transaction
    print(cout, total) << endl;
  }
  else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1; // indicate failure
  }
  return 0;
}
