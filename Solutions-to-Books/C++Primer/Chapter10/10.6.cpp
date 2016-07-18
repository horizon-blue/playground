// Exercise 10.6
// Using fill_n, write a program to set a sequence of int values to 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> ivec;
  cout << "Enter some numbers for the vector:\n";
  for(int temp; cin >> temp; ivec.push_back(temp));

  cout << "Before fill_n:";
  for(int num : ivec) cout << ' ' << num;
  cout << endl;

  fill_n(ivec.begin(), ivec.size(), 0);

  cout << "After fill_n:";
  for(int num : ivec) cout << ' ' << num;
  cout << endl;

  return 0;
}
