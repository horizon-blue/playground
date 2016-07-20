// Exercise 10.34
// Use reverse_iterators to print a vector in reverse order
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
  copy(ivec.crbegin(), ivec.crend(), oiter);

  return 0;
}
