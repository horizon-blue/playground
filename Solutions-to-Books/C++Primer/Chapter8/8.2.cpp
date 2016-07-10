// Exercise 8.1
// Write a function that takes and returns an istream&.
// The function should read the stream until it hits
// end-of-file. The function should print what it reads
// to the standard output. Reset the stream so that it is
// valid before returning the stream.
// Exercise 8.2
// Test your function by calling it, passing cin as
// an argument.
// Xiaoyan Wang 3/25/2016
#include <iostream>
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
  ifunc(cin);

  return 0;
}
