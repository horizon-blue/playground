// Exercise 10.35
// Now print the elements in reverse order using ordinary iterators
// Xiaoyan Wang 7/21/2016
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
  cout << "Enter some numbers for the vector:" << endl;
  vector<int> ivec;
  for(int i; cin >> i; ivec.push_back(i));

  ostream_iterator<int> oiter(cout, " ");
  for(auto iter = ivec.end(); iter != ivec.begin();)
    oiter = *(--iter);

  return 0;
}
