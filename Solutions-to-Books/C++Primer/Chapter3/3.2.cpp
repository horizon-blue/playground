/* Exercise 3.2: Write a program to read the standard input
 * a line at a time. Modify your program to read a word at
 * a time
 */
// Xiaoyan Wang 10/26/2015

#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  while (getline(cin, line))
    cout << line << endl;
  return 0;
}
