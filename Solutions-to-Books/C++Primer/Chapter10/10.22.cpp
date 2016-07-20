// Exercise 10.22
// Rewrite the program to count words of size 6 or less using
// functions in place of the lambdas.
// Mostly copied from 10.20.cpp
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
using placeholders::_1;

void biggies(vector<string>& words, string::size_type sz);
bool check_size(const string& s, string::size_type sz);

int main() {
  vector<string> words;
  cout << "Enter some words:" << endl;
  for(string temp; cin >> temp; words.push_back(temp));
  
  biggies(words, 6);

  return 0;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
  auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
  cout << count << ' ' << (count > 1 ? "words" : "word")
       << " of length " << sz << " or less" << endl;
  cout << endl;
}

bool check_size(const string& s, string::size_type sz) {
  return s.size() <= sz;
}
