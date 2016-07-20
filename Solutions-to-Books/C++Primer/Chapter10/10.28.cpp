// Exercise 10.28
// Copy a vector that holds the values from 1 to 9 inclusive, into three
// other containers. Use an inserter, a back_inserter, and a front_inserter,
// respectivly to add elements to these containers. Predict how the output
// sequence varies by the kind of inserter and verify your predictions by
// running your programs.
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main() {
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> ilst1, ilst2, ilst3;

  copy(ivec.begin(), ivec.end(), back_inserter(ilst1));
  copy(ivec.begin(), ivec.end(), front_inserter(ilst2));
  copy(ivec.begin(), ivec.end(), inserter(ilst3, ilst3.begin()));

  cout << "---Original---" << endl;
  cout << "ivec =";
  for(int num : ivec) cout << ' ' << num;
  cout << endl;

  cout << "---back_inserter---" << endl;
  cout << "ilst1 =";
  for(int num : ilst1) cout << ' ' << num;
  cout << endl;

  cout << "---front_inserter---" << endl;
  cout << "ilst2 =";
  for(int num : ilst2) cout << ' ' << num;
  cout << endl;

  cout << "---inserter---" << endl;
  cout << "ilst3 =";
  for(int num : ilst3) cout << ' ' << num;
  cout << endl;

  return 0;
}
