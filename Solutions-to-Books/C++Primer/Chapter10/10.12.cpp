// Exercise 10.12
// Write a function named compareIsbn that compares the isbn() members
// of two Sales_data objects. Use that function to sort a vector that
// holds Sales_data objects.
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h" // Using the one written in 7.26.cpp
using namespace std;

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2) {
  return sd1.isbn() < sd2.isbn();
}

int main() {
  vector<Sales_data> sdvec;
  cout << "Enter the ISBNs for the books:" << endl;
  for(string temp; cin >> temp; sdvec.emplace_back(temp));

  cout << "Before sorting:";
  for(const auto& sd : sdvec)
    print(cout, sd) << ' ';
  cout << endl;

  sort(sdvec.begin(), sdvec.end(), compareIsbn);

  cout << "After sorting:";
  for(const auto& sd : sdvec)
    print(cout, sd) << ' ';
  cout << endl;

  return 0;
}
