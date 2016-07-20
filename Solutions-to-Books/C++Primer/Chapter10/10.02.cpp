// Exercise 10.2
// Repeat the previous program, but read values into a list of strings
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
  list<string> slst;
  string s;
  cout << "Enter the key value: ";
  cin >> s;
  cout << "Enter some strings for the list:" << endl;
  for(string temp; cin >> temp; slst.push_back(temp));

  // using std::count to count the number of given value
  int numVal = count(slst.begin(), slst.end(), s);

  cout << s << " appears in the list for " << numVal
       << (numVal > 1 ? " time(s)." : " time.") << endl;

  return 0;
}
