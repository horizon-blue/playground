/* Write a program that reads a string
 * of characters including punctuation
 * and writes what was read but ith the
 * punctuation removed.
 * 
 * Xiaoyan Wang 10/26/2015
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string input, output;
  cin >> input;
  for(char c : input)
    if(!ispunct(c))
      output += c;
  cout << output << endl;

  return 0;
}
