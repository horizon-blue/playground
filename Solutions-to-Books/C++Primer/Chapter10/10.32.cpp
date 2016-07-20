// Exercise 10.32
// Rewrite the bookstore problem from Section 1.6 using a vector to hold
// the transactions and various algorithms to do the processing. Use sort
// with your compareIsbn function from Section 10.3.1 to arrange the
// transactions in order, and then use find and accumulate to do the sum.
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_item.h"
using namespace std;

// compareIsbn is copied from 10.12.cpp
bool compareIsbn(const Sales_item& sd1, const Sales_item& sd2);

int main() {
  cout << "Enter the information of the books:" << endl;
  istream_iterator<Sales_item> initer(cin), eof;
  vector<Sales_item> svec(initer, eof);

  sort(svec.begin(), svec.end(), compareIsbn);

  for(auto markb = svec.begin(), marke = markb; markb != svec.end();
      markb = marke) {
    marke = find_if(markb, svec.end(), [markb](const Sales_item& sd)
		    {return markb->isbn() != sd.isbn();});
    cout << accumulate(markb, marke, Sales_item(markb->isbn())) << endl;
  }
  return 0; 
}

bool compareIsbn(const Sales_item& sd1, const Sales_item& sd2) {
  return sd1.isbn() < sd2.isbn();
}
