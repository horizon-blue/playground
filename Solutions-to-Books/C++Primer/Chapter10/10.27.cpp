// Exercise 10.27
// In addition to unique, the library defines function named
// unique_copy that takes a third iterator denoting a destination
// into which to copy the unique elements. Write a program that uses
// unique_copy to copy the unique elements from a vector into an
// initially empty list.
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main() {
  vector<int> ivec;
  list<int> ilst;
  cout << "Enter some numbers for the vector:" << endl;
  for(int num; cin >> num; ivec.push_back(num));

  sort(ivec.begin(), ivec.end());
  unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));

  cout << "The contents in the vector are:";
  for(int num : ivec) cout << ' ' << num;
  cout << endl;
  
  cout << "The contents in the list are:";
  for(int num : ilst) cout << ' ' << num;
  cout << endl;

  return 0;
}
