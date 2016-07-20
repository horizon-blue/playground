// Exercise 10.37
// Given a vector that has ten elements, copy the elements from position
// 3 through 7 in reverse order to a list
// Xiaoyan Wang 7/21/2016
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
  vector<int> ivec;
  list<int> ilst;
  cout << "Enter ten integers for the vector:" << endl;
  for(int temp; cin >> temp; ivec.push_back(temp));

  copy(ivec.crbegin()+3, ivec.crend()-2, back_inserter(ilst));

  cout << "Numbers in the list:" << endl;
  for(int num : ilst)
    cout << num << ' ';
  cout << endl;

  return 0;
}
