/* Write a program to read a sequence of ints from
 * cin and store those values in a vector.
 *
 * Xiaoyan Wang 10/26/2015
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num;
  vector<int> vec;
  while(cin >> num)
    vec.push_back(num);
  for(int i : vec)
    cout << i << ' ';
  cout << endl;

  return 0;
}
