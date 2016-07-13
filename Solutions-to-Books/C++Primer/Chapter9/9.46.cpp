// Exercise 9.45
// Rewrite the previous exercises using a position
// and length to manage the strings. This time use
// only the insert function.
// Xiaoyan Wang 7/13/2016
#include <string>
#include <iostream>
using namespace std;

string append_strings(string name, const string& pre,
		    const string& suf) {
  name.insert(0, pre + " ");
  name.insert(name.size(), " " + suf);
  return name;
}

int main() {
  string name, prefix, suffix;
  cout << "Enter a name: ";
  getline(cin, name);
  cout << "Enter a prefix: ";
  getline(cin, prefix);
  cout << "Enter a suffix: ";
  getline(cin, suffix);

  cout << "After appending the prefix and suffix, the name"
       << " becomes " << append_strings(name, prefix, suffix)
       << ".\n";

  return 0;
}  
