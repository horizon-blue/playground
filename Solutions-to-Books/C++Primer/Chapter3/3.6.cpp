/* Use a range for to change all the characters
 * in a string to X.
 */
// Xiaoyan Wang 10/20/2015

#include <iostream>
#include <string>
using namespace std;

int main() {
  string a;
  cin >> a;
  for(char &c : a)
    c = 'X';
  cout << a << endl;

  return 0;
}
