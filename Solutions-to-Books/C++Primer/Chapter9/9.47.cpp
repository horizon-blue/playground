// Exercise 9.47
// Write a program that finds each numeric
// character and then each alphabetic character
// in the string "ab2c3d7R4E6". Write two versions
// of the program. The first should use find_first_of,
// and the second find_first_not_of
#include <string>
#include <iostream>
using namespace std;

int main() {
  string s = "ab2c3d7R4E6";
  string number = "0123456789";
  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  // find_first_of
  cout << "Using find_first_of:\nThe numbers are: \n";
  for(size_t pos = 0; (pos = s.find_first_of(number, pos)) != string::npos; ++pos)
    cout << s[pos] << " in position " << pos << ".\n";
  cout << "The alphabetic characters are: \n";
  for(size_t pos = 0; (pos = s.find_first_of(alphabet, pos)) != string::npos; ++pos)
    cout << s[pos] << " in position " << pos << ".\n";

  cout << endl;

  
  // find_first_not_of
  cout << "Using find_first_not_of:\nThe numbers are: \n";
  for(size_t pos = 0; (pos = s.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
    cout << s[pos] << " in position " << pos << ".\n";
  cout << "The alphabetic characters are: \n";
  for(size_t pos = 0; (pos = s.find_first_not_of(number, pos)) != string::npos; ++pos)
    cout << s[pos] << " in position " << pos << ".\n";

  return 0;
}
