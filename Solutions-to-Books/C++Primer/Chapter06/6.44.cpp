// Exercise 6.44 - Rewrite the isShorter function from 6.2.2
// to be inline
// Xiaoyan Wang 3/6/2016
#include <iostream>
#include <string>
using namespace std;

// compare the length of two strings
inline bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

int main() {
  string a, b;
  cout << "Enter two strings:\n";
  cin >> a >> b;
  if(isShorter(a, b))
    cout << a << " is shorter than " << b << ".\n";
  else
    cout << b << " is shorter than " << a << ".\n";

  return 0;
}
