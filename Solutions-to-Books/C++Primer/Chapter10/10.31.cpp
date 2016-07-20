// Exercise 10.31
// Update the program from the previous exercise so that it prints only
// the unique elements. Your program should use unqiue_copy
// Mostly copied from 10.30.cpp
// Xiaoyan Wang 7/20/2016
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  istream_iterator<int> initer(cin), eof;
  ostream_iterator<int> outiter(cout, " ");
  vector<int> ivec(initer, eof);

  sort(ivec.begin(), ivec.end());
  unique_copy(ivec.begin(), ivec.end(), outiter);

  cout << endl;
  
  return 0;
}
