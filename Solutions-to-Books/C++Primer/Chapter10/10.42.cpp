// Exercise 10.42
// Reimplement the program that eliminated duplicate words that we
// wrote in Section 10.2.3 to use a list instead of a vector
// Xiaoyan Wang 7/21/2016
#include <iostream>
#include <list>
#include <string>
using namespace std;

void elimDups(list<string>& words);

int main() {
  list<string> words;
  cout << "Enter some words:" << endl;
  for(string temp; cin >> temp; words.push_back(temp));

  elimDups(words);

  cout << "After calling elimDups, words =";
  for(const auto& s : words)
    cout << ' ' << s;
  cout << endl;

  return 0;
}

void elimDups(list<string>& words) {
  // sort words alphabetically
  words.sort();
  // reorder words and erase the duplicates
  words.unique();
}
