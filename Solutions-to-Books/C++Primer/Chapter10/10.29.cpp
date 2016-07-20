// Exercise 10.29
// Write a program using stream iterators to read a text file into a vector
// of strings
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("10.29.txt");
  istream_iterator<string> iiter(fin), eof;

  vector<string> svec(iiter, eof);

  cout << "svec =";
  for(const auto& s : svec)
    cout << ' ' << s;
  cout << endl;

  return 0;
}  
