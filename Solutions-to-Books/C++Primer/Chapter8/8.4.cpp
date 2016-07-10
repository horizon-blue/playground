// Exercise 8.4
// Write a function to open a file for input and read its
// contents into a vector of strings, storing each line as a
// seperate element in the vector
// Xiaoyan Wang 3/25/2016
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> process(string fileName) {
  vector<string> info;
  string temp;
  ifstream infile(fileName);
  while(getline(infile, temp))
    info.push_back(temp);
  return info;
}

int main(int argc, char *argv[]) {
  if(argc < 2)
    cerr << "Too few argument." << endl;
  else {
    vector<string> info = process(argv[1]);

    // check wether the function work correctly
    for(string s : info)
      cout << s << endl;
  }
  
  return 0;
}
