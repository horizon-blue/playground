// Exercise 11.20
// Rewrite the word-counting program from Section 11.1 to use insert instead
// of subscripting. Which program do you think is easier to write and read?
// Explain your reasoning.
// Mostly copied from 11.4.cpp
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>
#include <string>
using namespace std;

void process_word(string& word);

// parially copied from 11.3.cpp
int main() {
  map<string, size_t> word_count;
  set<string> exclude = {"the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word) {
    // process word to remove uppercase characters and punctuation
    process_word(word);
    if (exclude.find(word) == exclude.end()) {
    	++word_count.insert(make_pair(word, 0)).first->second;
    }
  }
  
  for (const auto& p : word_count)
    cout << p.first << " occurs " << p.second
	 << ((p.second > 1) ? " times." : " time.") << endl;

  return 0;
}

void process_word(string& word) {
  for (auto iter = word.begin(); iter != word.end();) {
    if (isupper(*iter)) {
      *iter = tolower(*iter);
      ++iter;
    }
    else if (ispunct(*iter))
      iter = word.erase(iter);
    else
      ++iter;
  }
}
