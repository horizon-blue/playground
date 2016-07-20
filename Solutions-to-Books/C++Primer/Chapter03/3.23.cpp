// Write a program to create a vector
// with ten int elements. Using an
// iterator, assign each element a
// value that is twice its current value.
// Xiaoyan Wang 11/18/2015
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec(10);
  for(auto i = vec.begin(); i != vec.end(); ++i) {
    cin >> *i;
    *i *= 10;
  }

  cout << endl;

  for(auto i = vec.begin(); i != vec.end(); ++i)
    cout << *i << endl;
  return 0;
}
