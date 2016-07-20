// Exercise 8.6
// Rewrite the bookstore program from Section 7.1.1 (p.256)
// to read its transactions from a file. Pass the name of the
// file as an argument to main (Section 6.2.5, p.218).
// Xiaoyan Wang 3/25/2016

// Mostly copied from 7.1.cpp in ~/Chapter7/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// The transaction-processing program
int main(int argc, char* argv[]) {
  if(argc < 2) {
    cerr << "Too few argument." << endl;
    return 1;
  }
  
  // file stream to get the input book information
  ifstream inFile(argv[1]);
  
  // variable to hold data for the next transaction
  Sales_data total;
  unsigned units;
  double price;
  // read the first transaction and ensure that there are
  // data to process
  if (inFile >> total.bookNo >> units >> price) {
    total.units_sold += units;
    total.revenue += units * price;
    // variable to hold the running sum
    Sales_data trans;
    unsigned trans_units;
    double trans_price; 
    while (inFile >> trans.bookNo >> trans_units >> trans_price) {
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
