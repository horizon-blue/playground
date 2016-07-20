/* Write a program to read two strings and
 * report whether the strings have the same
 * length, and if not, report which is longer.
 */
//Xiaoyan Wang 10/26/2015

#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  bool isSame = a.size() == b.size();
  cout << isSame << endl;
  if (!isSame)
    if(a.size() > b.size())
      cout << a << endl;
    else
      cout << b << endl;
  return 0;
}
