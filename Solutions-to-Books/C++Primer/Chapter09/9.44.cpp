// Exercise 9.43
// Rewrite the previous function using an index and
// replace.
// Xiaoyan Wang 7/13/2016
#include <iostream>
#include <string>
using namespace std;

void replacement(string& s, const string& oldVal,
		 const string& newVal) {
  for(decltype(s.size()) i = 0; i + oldVal.size() <= s.size();) {
    if(oldVal == s.substr(i, oldVal.size())) {
      s.replace(i, oldVal.size(), newVal);
      i += newVal.size();
    }
    else
      ++i;
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
