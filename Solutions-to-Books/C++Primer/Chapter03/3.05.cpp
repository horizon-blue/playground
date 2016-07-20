/* Write a program to read strings from the
 * standard input, concatenating what is read
 * into one large string. Print the 
 * concatenated string. Next, change the
 * program to separate adjacent input string
 * by a space.
 */
// Xiaoyan Wang 10/26/2015
#include <iostream>
#include <string>
using namespace std;

int main() {
  string total = "", temp;
  while(cin >> temp)
    total += temp + " ";
  cout << total << endl;
  return 0;
}
