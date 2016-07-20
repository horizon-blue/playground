// Exercise 10.17
// Rewrite exercise 10.12 from section 10.3.1 to use a lambda in the
// call to sort instead of the compareIsbn function
// Mostly copied from 10.12.cpp
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h" // Using the one written in 7.26.cpp
using namespace std;

int main() {
  vector<Sales_data> sdvec;
  cout << "Enter the ISBNs for the books:" << endl;
  for(string temp; cin >> temp; sdvec.emplace_back(temp));

  cout << "Before sorting:";
  for(const auto& sd : sdvec)
    print(cout, sd) << ' ';
  cout << endl;

  sort(sdvec.begin(), sdvec.end(),
       [](const Sales_data& sd1, const Sales_data& sd2){
	 return sd1.isbn() < sd2.isbn();});

  cout << "After sorting:";
  for(const auto& sd : sdvec)
    print(cout, sd) << ' ';
  cout << endl;

  return 0;
}
