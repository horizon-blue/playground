// Exercise 9.4
// Write a function that takes a pair of iterators to a vector<int>
// and an int value. Look for that value in the range and return bool
// indicating whether it was found.
// Xiaoyan Wang 4/18/2016
#include <iostream>
#include <vector>
using namespace std;

bool finded(vector<int>::const_iterator first,
	  vector<int>::const_iterator last, int value) {
  for(auto it = first; it != last; ++it)
    if(*it == value)
      return true;
  return false;
}

int main() {
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int i;
  cin >> i;

  if(finded(ivec.begin(), ivec.end(), i))
    cout << i << " is in the vector." << endl;

  return 0;
}
