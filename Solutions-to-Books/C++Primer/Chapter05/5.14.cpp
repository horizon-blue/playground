// Xiaoyan Wang 12/25/2015
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main() {
  int maxRepeat = 0;
  string word, maxWord;
  string previous = "";
  int temp;
  while(cin >> word) {
    if(word != previous) {
      previous = word;
      temp = 1;
    }
    else
      ++temp;
    if(temp > maxRepeat) {
      maxRepeat = temp;
      maxWord = word;
    }
  }
  
  cout << "The word " << maxWord << " appears ";
  cout << maxRepeat << " times." << endl;

  return 0;
}
