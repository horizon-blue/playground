// Exercise 9.19
// Rewrite the program from the previous exercise to
// use a list. List the changes you needed to make.
// Xiaoyan Wang 7/7/2016
#include <list>
#include <iostream>
#include <string>
using namespace std;

int main() {
  list<string> slst;
  for(string temp; cin >> temp; slst.push_back(temp));

  for(auto iter = slst.begin(); iter != slst.end(); ++iter)
    cout << *iter << ' ';
  cout << endl;

  return 0;
}
