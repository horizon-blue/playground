// Write a program to compare two strings.
// Now write a program to compare the
// value of two C-style strings.
// Xiaoyan Wang 11/19/2015
#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cout << "Enter two strings (maximum 100 characters):\n";
  cin >> a >> b;
  const char * c = new char[a.length()+1];
  c = a.c_str();
  const char * d = new char[b.length()+1];
  d = b.c_str();
  cout << "a is ";
    if(a<b)
      cout << "less than b" << endl;
    else if(a==b)
      cout << "equal to b" << endl;
    else
      cout << "greater than b" << endl;
  int cIsGreater = 0;
  int dIsGreater = 0;
  for(int i = 0; i < a.length() && i < b.length(); ++i) {
    if(c[i] > d[i] || (i == b.length()-1 && !(i == a.length()-1))) {
      cIsGreater = 1;
      break;
    }
    else if(c[i] < d[i] || (i == a.length()-1 && !(i == b.length()-1))) {
      dIsGreater = 1;
      break;
    }
  }
  
  cout << "c is ";
    if(dIsGreater)
      cout << "less than d" << endl;
    else if(cIsGreater)
      cout << "greater than d" << endl;
    else
      cout << "equal to d" << endl;

  return 0;
}
