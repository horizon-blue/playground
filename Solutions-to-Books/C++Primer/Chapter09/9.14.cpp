// Exercise 9.14
// Write a program to assign the elements from a
// list of char* pointers to C-style character
// strings to a vector of strings
// Xiaoyan Wang 7/2/2016
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main() {
  list<char*> clst = {"apple", "banana", "orange"};
  vector<string> svec;

  svec.assign(clst.begin(), clst.end());
  
  cout << "Contents in vector<string>: ";
  for(const string& s : svec)
    cout << '\"' << s << "\" ";
  cout << endl;

  return 0;
}
  
