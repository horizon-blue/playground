// Exercise 10.20
// The library defines an algorithm named count_if. Like find_if, this
// function takes a pair of iterators denoting an input range and a
// predicate that it applies to each element in the given range.
// count_if returns a count of how often the predicate is true. Use
// count_if to rewrite the portion of our program that counted how
// many words are greater than length 6.
// Mostly copied from 10.19.cpp
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
  
  biggies(words, 6);

  return 0;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
  elimDups(words);

  auto count = count_if(words.begin(), words.end(),
		    [sz](const string& s) {return s.size() >= sz;});
  cout << count << ' ' << (count > 1 ? "words" : "word")
       << " of length " << sz << " or longer" << endl;
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
