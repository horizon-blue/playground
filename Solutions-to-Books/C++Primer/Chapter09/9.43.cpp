// Exercise 9.43
// Write a function that takes three strings, s,
// oldVal, and newVal. Using iterators, and the
// insert and erase functionts replace all
// instances of oldVal that appear in s by newVal.
// Test your function by using it to replace
// common abbreviations, such as "tho" by
// "though" and "thru" by "through".
// Xiaoyan Wang 7/13/2016
#include <iostream>
#include <string>
using namespace std;

void replacement(string& s, const string& oldVal,
		 const string& newVal) {
  for(auto iter = s.begin();
      iter <= s.end() - oldVal.size();) {
    if(oldVal == string(iter, iter + oldVal.size())) {
      iter = s.erase(iter, iter + oldVal.size());
      iter = s.insert(iter, newVal.begin(), newVal.end());
      iter += newVal.size();
    }
    else
      ++iter;
  }
}

int main() {
  string s, oldVal, newVal;
  cout << "Enter string s: ";
  getline(cin, s);
  cout << "Enter string oldVal: ";
  getline(cin, oldVal);
  cout << "Enter string newVal: ";
  getline(cin, newVal);

  replacement(s, oldVal, newVal);
  cout << "After replacement, string s = \"" << s << "\".\n";

  return 0;
}
