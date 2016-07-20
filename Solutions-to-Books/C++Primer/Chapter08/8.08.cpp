// Exercise 8.8
// Revise the program from the previous exercise to append
// its output to its given file. Run the program on the same
// output file at least twice to ensure that the data are
// preserved.
// Xiaoyan Wang 3/25/2016

// Mostly copied from 8.6.cpp
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
  if(argc < 3) {
    cerr << "Too few argument." << endl;
    return 1;
  }
  
  // file stream to get the input book information
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2], ofstream::app);
  
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
	outFile << total.bookNo << ' ' << total.units_sold
	     << ' ' << total.revenue << ' ' << price << endl;
	// Total now refers to the next book
	total = trans;
      }
    }
    // print the last transaction
    outFile << total.bookNo << ' ' << total.units_sold
	 << ' ' << total.revenue << ' ' << price << endl;
  }
  else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1; // indicate failure
  }
  return 0;
}
