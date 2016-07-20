// Exercise 10.18
// Rewrite biggies to use partition instead of find_if
// Mostly copied from 10.16.cpp
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void elimDups(vector<string>& words);
void biggies(vector<string>& words, vector<string>::size_type sz);

int main() {
  vector<string> words;
  vector<string>::size_type sz;
  cout << "Enter some words:" << endl;
  for(string temp; cin >> temp; words.push_back(temp));
  cin.clear();
  cout << "Enter a length: ";
  cin >> sz;
  
  biggies(words, sz);

  return 0;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
  elimDups(words);

  auto wc = partition(words.begin(), words.end(),
		    [sz](const string& s) {return s.size() >= sz;});
  auto count = wc - words.begin();
  cout << count << ' ' << (count > 1 ? "words" : "word")
       << " of length " << sz << " or longer" << endl;
  for_each(words.begin(), wc, [](const string& s){cout << s << ' ';});
  cout << endl;
}

// copied from 10.11.cpp
void elimDups(vector<string>& words) {
  // sort words alphabetically
  sort(words.begin(), words.end());
  // reorder words
  auto mark = unique(words.begin(), words.end());
  // erase non-unique words after the mark
  words.erase(mark, words.end());
}
