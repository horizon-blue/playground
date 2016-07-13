// Exercise 9.38
// Write a program to explore how vectors
// grow in the library you use.
// Xiaoyan Wang 7/13/2016
#include <vector>
#include <iostream>
using namespace std;

inline void printinfo(const vector<int>& ivec) {
  cout << "ivec.size(): " << ivec.size() << '\n';
  cout << "ivec.capacity(): " << ivec.capacity() << '\n';
  cout << "--------" << endl;
}

int main() {
  vector<int> ivec;
  printinfo(ivec);

  for(int i = 0; i < 10; ++i)
    ivec.push_back(i);
  printinfo(ivec);

  ivec.insert(ivec.end(), 100, 10);
  printinfo(ivec);

  for(int i = 0; i < 35; ++i)
    ivec.push_back(i);
  printinfo(ivec);

  return 0;
}
