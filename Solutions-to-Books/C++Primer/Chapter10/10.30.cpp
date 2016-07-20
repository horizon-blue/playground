// Exercise 10.30
// Use stream iterators, sort, and copy to read a sequence of integers from
// the standard input, sort them, and then write them back to the standard
// output.
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

  copy(ivec.begin(), ivec.end(), outiter);

  cout << endl;
  
  return 0;
}
