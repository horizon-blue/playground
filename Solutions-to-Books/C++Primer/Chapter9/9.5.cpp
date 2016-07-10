// Exercise 9.5
// Rewrite the previous program to return an iterator to the
// requested element. Note that the program must handle the case
// where the element is not found.
// Xiaoyan Wang 4/18/2016
#include <iostream>
#include <vector>
using namespace std;

vector<int>::const_iterator finded(vector<int>::const_iterator first,
	  vector<int>::const_iterator last, int value) {
  for(auto it = first; it != last; ++it)
    if(*it == value)
      return it;
  return last;
}

int main() {
  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int i;
  cin >> i;

  if(finded(ivec.begin(), ivec.end(), i) != ivec.end())
    cout << i << " is in the vector." << endl;

  return 0;
}
