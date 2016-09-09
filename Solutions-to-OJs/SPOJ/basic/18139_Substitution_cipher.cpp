// Xiaoyan Wang 10/25/2015
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, m;
  string cipher;
  cin >> n;
  cin >> cipher;
  cin >> m;
  string text;
  while(getline(cin, text)) {
    for (char &c : text) {
      for (int i = 0; i <= n; ++i) {
	if(c == cipher[i]) {
	  c = cipher[(i+1)%n];
	  break;
	}
      }
    }
    if(!text.empty())
      cout << text << endl;
  }
  return 0;
}
