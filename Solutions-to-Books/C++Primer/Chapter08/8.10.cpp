// Exercise 8.10
// Write a program to store each line from a file
// in a vector<string>. Now use an istringstream
// to read each element from the vector a word at a
// time.
// Xiaoyan Wang 3/25/2016
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cerr << "Too few argument." << endl;
    return 1;
  }

  // Part 1: store each line from a file in a vector<string>
  ifstream infile(argv[1]);
  string line;
  vector<string> info;
  while(getline(infile, line))
    info.push_back(line);

  // Part 2: use an istringstream to read each element from
  // the vector a word at a time
  for(string s : info) {
    istringstream iss(s);
    string temp;
    while(iss >> temp)
      cout << temp << endl;
  }

  return 0;
}
