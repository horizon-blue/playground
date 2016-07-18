// Exercise 10.3
// Use accumulate to sum the elements in a vector<int>
#include <numeric>
#include <vector>
#include <iostream>
using std::cin; using std::cout;
using std::accumulate;
using std::vector;

int main() {
  vector<int> ivec;
  cout << "Enter some numbers to put into the vector:\n";
  for(int temp; cin >> temp; ivec.push_back(temp));

  int sum = accumulate(ivec.begin(), ivec.end(), 0);

  cout << "The sum of the numbers in the vector is "
       << sum << '.' << std::endl;

  return 0;
}
