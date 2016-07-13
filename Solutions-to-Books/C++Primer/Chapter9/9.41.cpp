// Exercise 9.41
// Write a program to initializes a string
// from a vector<char>.
// Xiaoyan Wang 7/13/2015
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<char> cvec;
  cout << "Enter the contents of the vector, "
       << "enter '0' to quit." << endl;
  for(char c; cin >> c && c != '0'; cvec.push_back(c));

  cout << "The characters in the vectors are: ";
  for(char c : cvec)
    cout << ' ' << c;
  cout << endl;
  
  string s(cvec.begin(), cvec.end());
  cout << "The string constructed by the vector is: "
       << s << endl;

  return 0;
}
