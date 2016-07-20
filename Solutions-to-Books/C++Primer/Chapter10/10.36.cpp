// Exercise 10.36
// Use find to find the last element in a list of ints with value 0
// Xiaoyan Wang 7/21/2016
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

int main() {
  list<int> ilst;
  cout << "Enter some numbers for the list:" << endl;
  for(int temp; cin >> temp; ilst.push_back(temp));

  auto mark = find(ilst.crbegin(), ilst.crend(), 0);

  if(mark != ilst.crend()) {
    cout << "0 is found. The elements after 0 are";
    for(auto iter = mark.base(); iter != ilst.end(); ++iter)
      cout << ' ' << *iter;
  }
  else
    cout << "0 is not found.";

  cout << endl;

  return 0;
}
