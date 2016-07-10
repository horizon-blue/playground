// Xiaoyan Wang 12/26/2015
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::string;

int main() {
  string str1, str2;
  char response;
  do {
    cout << "Enter two strings:\n";
    cin >> str1 >> str2;

    if(str1 > str2)
      cout << '\"' << str2 << "\" is less than \"" << str1 << "\".\n";
    else if(str2 > str1)
      cout << '\"' << str1 << "\" is less than \"" << str2 << "\".\n";
    else
      cout << '\"' << str1 << "\" and \"" << str2 << "\" are equal.\n";

    cout << "Compare again? (y/n): ";
  } while (cin >> response && response == 'y');

  return 0;
}
