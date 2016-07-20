// A letter has an ascender if, as with d or f,
// part of the letter extends above the middle of
// the line. A letter has a descender if, as with p
// or g, part of the letter extends below the line.
// Write a program that reads a file containing words
// and reports the longest word that contains neither
// ascenders nor descenders.
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

inline bool qualify(const string& s) {
  return s.find_first_not_of("aceimnorsuvwxz") == string::npos;
}

int main() {
  string name_of_file;
  cout << "Enter the name of the file:\n";
  cin >> name_of_file;
  ifstream infile(name_of_file);
  size_t maxlength = 0;
  string result;
  for(string temp; infile >> temp;) {
    if(qualify(temp) && temp.size() > maxlength) {
      result = temp;
      maxlength = temp.size();
    }
  }

  cout << "The longest word that contains neither "
       << "ascenders nor descenders is " << result
       << endl;
  
  return 0;
}
