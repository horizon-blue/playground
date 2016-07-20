// Exercise 9.15
// Write a program to determine whether two
// vector<int>s are equal.
// Exercise 9.16
// Repeat the previous program, but compare elements
// in a list<int> to a vector<int>
// Xiaoyan Wang 7/2/2016
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main() {
  vector<int> ivec1 = {1, 3, 5, 7, 9, 12};
  vector<int> ivec2 = {1, 3, 9};
  list<int> ilst = {1, 3, 5, 7};
  cout << "vector<int> ivec1 = {1, 3, 5, 7, 9, 12};\n"
       << "vector<int> ivec2 = {1, 3, 9};\n"
       << "list<int> ilst = {1, 3, 5, 7};" << endl;
  if(ivec1 == ivec2)
    cout << "ivec1 equals ivec2" << endl;
  else if(ivec1 < ivec2)
    cout << "ivec1 is less than ivec2" << endl;
  else
    cout << "ivec1 is greater than ivec2" << endl;

  if(ivec1 == vector<int>(ilst.begin(), ilst.end()))
    cout << "ivec1 equals ilst" << endl;
  else if(ivec1 < vector<int>(ilst.begin(), ilst.end()))
    cout << "ivec1 is less than ilst" << endl;
  else
    cout << "ivec1 is greater than ilst" << endl;

  return 0;
}  
