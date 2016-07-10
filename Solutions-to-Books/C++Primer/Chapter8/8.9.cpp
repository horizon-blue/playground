// Exercise 8.9
// Use the function you wrote for the first exercise in
// Section 8.1.2 (p.314) to print the contents of an
// istringstream object.
// Xiaoyan Wang 3/25/2016

// Mostly copied from 8.2.cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

istream& ifunc(istream& is) {
  string s;
  while(is >> s)
    cout << s << endl;
  is.clear();
  return is;
}

int main() {
  string a = "apple is good.";
  istringstream iss(a);
  ifunc(iss);
  return 0;
}
