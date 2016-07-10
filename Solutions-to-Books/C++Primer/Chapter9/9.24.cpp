// Exercise 9.24
// Write a program that fetches the first element in
// a vector using at, the subscript operator, front,
// and begin. Test your program on an empty vector.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> ivec = {1, 2, 3, 4, 5}, ivec2;
  cout << "ivec = {1, 2, 3, 4, 5}\n"
       << "ivec2 is empty.\n";

  cout << ivec.at(0) << ' ' << ivec[0] << ' '
       << ivec.front() << ' ' << *ivec.begin() << '\n';

  // Testing
  cout << ivec2.at(0) << ' ' << ivec2[0] << ' '
       << ivec2.front() << ' ' << *ivec2.begin() << endl;

  return 0;
}
