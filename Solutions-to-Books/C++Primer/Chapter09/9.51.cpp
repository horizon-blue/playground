// Exercise 9.51
// Write a class that has three unsigned members
// representing year, month, and day. Write a
// constructor that takes a string representing a
// date. Your constructor should handle a variety
// of date formats, such as January 1, 1900, 1/1/1900,
// Jan 1, 1900, and so on.
// Xiaoyan Wang 7/15/2016
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::getline;
using std::cin;

class Date {
public:
  Date() = default;
  Date(const string& s);
  friend std::ostream& operator <<(std::ostream& os, const Date& d);
  
private:
  unsigned year;
  unsigned month;
  unsigned day;
};

int main() {
  cout << "Enter a date:\n";
  string dinput;
  getline(cin, dinput);
  Date d(dinput);
  cout << d << std::endl;
  
  return 0;
}

std::ostream& operator <<(std::ostream& os, const Date& d) {
  os << "year = " << d.year
     << ", month = " << d.month
     << ", day = " << d.day;
  return os;
}

// the most important part >:D
Date::Date(const string& s) {
  string number = "0123456789";
  string alphabet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  string::size_type mark1 = 0, mark2 = 0, mark3 = 0;
  if(alphabet.find(s[0]) != string::npos) { // Jan 1, 1900 or Janurary 1, 1900
    mark1 = s.find(' ') + 1;
    mark2 = s.find(',');
    mark3 = s.rfind(' ') + 1;
    switch (s[0]) {
    case 'J':
    case 'j':
      if(s[1] == 'a' || s[1] == 'A')
	month = 1;
      else if(s[2] == 'n' || s[2] == 'N')
	month = 6;
      else
	month = 7;
      break;
    case 'F':
    case 'f':
      month = 2;
      break;
    case 'M':
    case 'm':
      if(s[1] == 'o' || s[1] == 'O')
	month = 3;
      else
	month = 5;
      break;
    case 'A':
    case 'a':
      if(s[1] == 'p' || s[1] == 'P')
	month = 4;
      else
	month = 8;
      break;
    case 'S':
    case 's':
      month = 9;
      break;
    case 'O':
    case 'o':
      month = 10;
      break;
    case 'N':
    case 'n':
      month = 11;
      break;
    case 'D':
    case 'd':
      month = 12;
      break;
    }
  }
  else { // 1/1/1900
    mark1 = s.find('/') + 1;
    mark2 = s.rfind('/');
    mark3 = mark2 + 1;
    month = stoi(s.substr(0, mark1 - 1));
  }
  day = stoi(s.substr(mark1, mark2 - mark1));
  year = stoi(s.substr(mark3));
}

