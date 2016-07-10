// Xiaoyan Wang 12/27/2015
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string previous = "", current;
  bool repeated = false;

  while(cin >> current) {
    if(!isupper(current[0]))
      continue;
    if(previous != current)
      previous = current;
    else {
      repeated = true;
      break;
    }
  }

  if(repeated)
    cout << "The word \"" << previous
	 << "\" was repeated." << endl;
  else
    cout << "No word starts with uppercase letter was repeated." << endl;

  return 0;
}
