// Exercise 9.45
// Write a function that takes a string representing
// a name and two other strings representing a prefix,
// such as "Mr." or "Ms." and a suffix, such as "Jr."
// or "III". Using iterators and the insert and append
// functions, generate and return a new string with
// the suffix and prefix added to the given name.
// Xiaoyan Wang 7/13/2016
#include <string>
#include <iostream>
using namespace std;

string append_strings(string name, const string& pre,
		    const string& suf) {
  name.insert(name.begin(), {' '});
  name.insert(name.begin(), pre.begin(), pre.end());
  name.append(" ");
  name.append(suf);
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
