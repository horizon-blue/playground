// Exercise 11.3
// Write your own version of the word-counting program.
// Xiaoyan Wang 7/22/2016
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  map<string, size_t> word_count;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
			 "the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word)
    // if word is not in exclude
    if (exclude.find(word) == exclude.end())
      ++word_count[word];
  for (const auto& p : word_count)
    cout << p.first << " occurs " << p.second
	 << ((p.second > 1) ? " times." : " time.") << endl;

  return 0;
}
