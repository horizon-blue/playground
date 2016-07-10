// Exercise 9.18
// Write a program to read a sequence of strings
// from the standard input into a deque. Use iterators
// to write a loop to print the elements in the deque.
// Xiaoyan Wang 7/7/2016
#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  deque<string> sd;
  string temp;

  while(cin >> temp)
    sd.push_back(temp);

  for(auto iter = sd.begin(); iter != sd.end(); ++iter)
    cout << *iter << ' ';
  cout << endl;

  return 0;
}
