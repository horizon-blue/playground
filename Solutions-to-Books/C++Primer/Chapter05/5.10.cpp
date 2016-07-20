// Xiaoyan Wang 12/25/2015
#include <iostream>
using namespace std;

int main() {
  char ch;
  int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
  while(cin >> ch) {
    switch(ch) {
    case 'a':
    case 'A':
      ++aCount;
      break;
    case 'e':
    case 'E':
      ++eCount;
      break;
    case 'i':
    case 'I':
      ++iCount;
      break;
    case 'o':
    case 'O':
      ++oCount;
      break;
    case 'u':
    case 'U':
      ++uCount;
      break;
    }
  }

  cout << "Number of vowel a: \t" << aCount << endl;
  cout << "Number of vowel e: \t" << eCount << endl;
  cout << "Number of vowel i: \t" << iCount << endl;
  cout << "Number of vowel o: \t" << oCount << endl;
  cout << "Number of vowel u: \t" << uCount << endl;

  return 0;
}
