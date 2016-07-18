// Exercise 10.1
// The algorithm header defines a function named count
// that, like find, takes a pair of iterators and a value.
// count returns a count of how often that value appears.
// Read a sequence of ints into a vector and print the count
// of how many elements have a given value.
// Xiaoyan Wang 7
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> ivec;
  int num;
  cout << "Enter the key value: ";
  cin >> num;
  cout << "Enter some numbers for the vector:" << endl;
  for(int temp; cin >> temp; ivec.push_back(temp));

  // using std::count to count the number of given value
  int numVal = count(ivec.begin(), ivec.end(), num);

  cout << num << " appears in the vector for " << numVal
       << " time(s)." << endl;

  return 0;
}
