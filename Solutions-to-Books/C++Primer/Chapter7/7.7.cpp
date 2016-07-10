// Exercise 7.7
// Rewrite the transaction-processing program you wrote for
// the exercises in Section 7.1.2 (p.260) to use these new
// functions
// Xiaoyan Wang 3/7/2016
#include <iostream>
#include <string>
// include the Sales_data class from previous exercise
#include "7.6.cpp"
using namespace std;

// The transaction-processing program
// Mostly copied from 7.3.cpp with some modifications
int main() {
  // variable to hold data for the next transaction
  Sales_data total;
  // read the first transaction and ensure that there are
  // data to process
  if (read(cin, total)) {
    // variable to hold the running sum
    Sales_data trans;
    while (read(cin, trans)) {
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
