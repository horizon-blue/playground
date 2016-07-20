// Exercise 6.42 - Give the second parameter of make_plural
// a default argument of 's'. Test your program by printing
// singular and plural versions of the words success and
// failure
// Xiaoyan Wang 3/6/2016
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

// return the plural version of word if ctr is greater
// than 1
string make_plural(size_t ctr, const string &word,
		   const string &ending = "s");

int main() {
  size_t count;
  string word;
  cout << "Enter a word: ";
  cin >> word;
  cout << "Enter a count: ";
  cin >> count;
  char response;
  cout << "Do you want to enter a postfix? (y/n) ";
  do {
    response = getchar();
  } while (response != 'y' && response != 'n');

  if(response == 'y') {
    string postfix;
    cout << "Enter your postfix: ";
    cin >> postfix;
    cout << "The new form of the word is "
	 << make_plural(count, word, postfix);
  }
  else
    cout << "The new form of the word is "
	 << make_plural(count, word);
    
  return 0;
}

string make_plural(size_t ctr, const string &word,
		   const string &ending) {
  return (ctr > 1)? word + ending : word;
}
