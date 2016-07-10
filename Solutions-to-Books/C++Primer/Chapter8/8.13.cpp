// Exercise 8.13
// Rewrite the phone number program from this section to
// read from a named file rather than from cin.
// Xiaoyan Wang 3/26/2016

//Mostly copied from 8.11.cpp
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool valid(const string& num) {
  return isdigit(num[0]) && num.length() == 10;
}

string format(const string& num) {
  ostringstream oss;
  oss << '(' << num.substr(0,3) << ')'
      << num.substr(3,3) << '-'
      << num.substr(6,4);
  return oss.str();
}

// simple class to represent the input data
struct PersonInfo {
  string name;
  vector<string> phones;
};

int main(int argc, char *argv[]) {
  if(argc < 2) {
    cerr << "Too few argument." << endl;
    return 1;
  }
  ifstream infile(argv[1]);
  string line, word;
  vector<PersonInfo> people;
  // moving definition of istringstream outside
  istringstream record;
  // read the input a line at a time until cin hits
  // end-of-file (or another error)
  while(getline(infile, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while(record >> word)
      info.phones.push_back(word);
    people.push_back(info);
    // This is the change that we need to make: add a clear() at the end
    record.clear();
  }

  // Using ostringstreams to format information
  for (const auto &entry : people) {
    ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) {
      if (!valid(nums))
	badNums << " " << nums;
      else
	formatted << " " << format(nums);
    }
    if (badNums.str().empty())
      cout << entry.name << " " << formatted.str() << endl;
    else
      cerr << "input error: " << entry.name << " invalid number(s) "
	   << badNums.str() << endl;
  }
  
  return 0;
}
