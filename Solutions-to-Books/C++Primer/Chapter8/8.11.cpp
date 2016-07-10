// Exercise 8.11
// The program in this section defined its istringstream
// object inside the outer while loop. What changes would
// you need to make if record were defined outside that
// loop? Rewrite the program, moving the definition of
// record outside the while, and see wheter you thought of
// all the changes that are needed.
// Xiaoyan Wang 3/25/2016
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// simple class to represent the input data
struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  string line, word;
  vector<PersonInfo> people;
  // moving definition of istringstream outside
  istringstream record;
  // read the input a line at a time until cin hits
  // end-of-file (or another error)
  while(getline(cin, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while(record >> word)
      info.phones.push_back(word);
    people.push_back(info);
    // This is the change that we need to make: add a clear() at the end
    record.clear();
  }

  // testing
  cout << "---Testing---\n"
       << "Print the information store in the vector"
       << " to see wheter the program works correctly."
       << endl;
  for(PersonInfo p : people) {
    cout << "Name: " << p.name << endl;
    for(string n : p.phones)
      cout << "  " << n << endl;
    cout << endl;
  }
  
  return 0;
}
