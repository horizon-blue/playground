// Exercise 10.11
// Write a program that uses stable_sort and isShorter to sort a vector
// passed to your version of elimDups. Print the vector to verify that your
// program is correct.
// Mostly copied from 10.9.cpp
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string>& words);
bool isShorter(const string& s1, const string& s2);
void printvec(const vector<string>& vec);

int main() {
  vector<string> words;
  cout << "Enter some words for the vector:" << endl;
  for(string temp; cin >> temp; words.push_back(temp));

  elimDups(words);
  cout << "After calling elimDups:";
  printvec(words);

  stable_sort(words.begin(), words.end(), isShorter);
  cout << "After calling stable_sort:";
  printvec(words);

  return 0;
}

void elimDups(vector<string>& words) {
  // sort words alphabetically
  sort(words.begin(), words.end());
  // reorder words
  auto mark = unique(words.begin(), words.end());
  // erase non-unique words after the mark
  words.erase(mark, words.end());
}

bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}

// helper function
inline void printvec(const vector<string>& vec) {
  for(const auto& s : vec) cout << ' ' << s;
  cout << endl;
}
