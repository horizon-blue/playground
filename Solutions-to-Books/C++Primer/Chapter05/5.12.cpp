// Xiaoyan Wang 12/25/2015
#include <iostream>
using namespace std;

int main() {
  char ch;
  int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
  int spCount = 0, nlCount = 0, tbCount = 0;
  int ffCount = 0, flCount = 0, fiCount = 0;
  bool preIsF = false;
  while(cin.get(ch)) {
    switch(ch) {
    case 'f':
    case 'F':
      if(!preIsF)
	preIsF = true;
      else
	++ffCount;
      break;
    case 'a':
    case 'A':
      preIsF = false;
      ++aCount;
      break;
    case 'e':
    case 'E':
      preIsF = false;
      ++eCount;
      break;
    case 'i':
    case 'I':
      if(preIsF)
	++fiCount;
      preIsF = false;
      ++iCount;
      break;
    case 'o':
    case 'O':
      preIsF = false;
      ++oCount;
      break;
    case 'u':
    case 'U':
      preIsF = false;
      ++uCount;
      break;
    case ' ':
      preIsF = false;
      ++spCount;
      break;
    case '\n':
      preIsF = false;
      ++nlCount;
      break;
    case '\t':
      preIsF = false;
      ++tbCount;
      break;
    case 'l':
    case 'L':
      if(preIsF)
	++flCount;
      preIsF = false;
      break;
    default:
      preIsF = false;
      break;
    }
  }

  cout << "Number of vowel a: \t" << aCount << endl;
  cout << "Number of vowel e: \t" << eCount << endl;
  cout << "Number of vowel i: \t" << iCount << endl;
  cout << "Number of vowel o: \t" << oCount << endl;
  cout << "Number of vowel u: \t" << uCount << endl;
  cout << "Number of spaces: \t" << spCount << endl;
  cout << "Number of new lines: \t" << nlCount << endl;
  cout << "Number of tabs: \t" << tbCount << endl;
  cout << "Number of ff: \t" << ffCount << endl;
  cout << "Number of fl: \t" << flCount << endl;
  cout << "Number of fi: \t" << fiCount << endl;
  return 0;
}
