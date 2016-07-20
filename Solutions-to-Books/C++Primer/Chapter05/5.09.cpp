// Xiaoyan Wang 12/25/2015
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  char ch;
  int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
  while(ch = getchar()) {
    if (ch == '.')
      break;
    else if (ch == 'a' || ch == 'A')
      ++aCount;
    else if (ch == 'e' || ch == 'E')
      ++eCount;
    else if (ch == 'i' || ch == 'I')
      ++iCount;
    else if (ch == 'o' || ch == 'O')
      ++oCount;
    else if (ch == 'u' || ch == 'U')
      ++uCount;
  }

  cout << "Number of vowel a: \t" << aCount << endl;
  cout << "Number of vowel e: \t" << eCount << endl;
  cout << "Number of vowel i: \t" << iCount << endl;
  cout << "Number of vowel o: \t" << oCount << endl;
  cout << "Number of vowel u: \t" << uCount << endl;

  return 0;
}
