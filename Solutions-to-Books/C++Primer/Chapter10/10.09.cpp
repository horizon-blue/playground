// Exercise 10.9
// Implement your own version of elimDups. Test your program by printing
// the vector after you read the input, after the call to unique, and after
// the call to erase
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// helper function
inline void printvec(const vector<string>& vec) {
  for(const auto& s : vec) cout << ' ' << s;
  cout << endl;
}

void elimDups(vector<string>& words) {
  cout << "Before sorting:";
  printvec(words);
  // sort words alphabetically
  sort(words.begin(), words.end());
  cout << "After sorting:";
  printvec(words);
  // reorder words
  auto mark = unique(words.begin(), words.end());
  cout << "After calling unique:";
  printvec(words);
  // erase non-unique words after the mark
  words.erase(mark, words.end());
  cout << "After calling erase:";
  printvec(words);
}

int main() {
  vector<string> words;
  cout << "Enter some words for the vector:" << endl;
  for(string temp; cin >> temp; words.push_back(temp));

  elimDups(words);

  return 0;
}  
