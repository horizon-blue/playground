/*
ID: skyline12
PROG: palsquare
LANG: C++11
*/
// Xiaoyan Wang 4/22/2016
#include <fstream>
#include <string>
using std::to_string;
using std::string;
using std::ifstream;
using std::ofstream;

bool isPld(const string& s);
string convertBase(int num, int base);
const string NUMS = "0123456789ABCDEFGHIJ";

int main() {
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");

  int B; // base
  fin >> B;

  for(int n = 1; n <= 300; ++n) {
    string converted = convertBase(n*n, B);
    if(isPld(converted))
      fout << convertBase(n, B) << ' '
	   << converted << '\n';
  }

  fin.close();
  fout.close();
  return 0;
}

string convertBase(int num, int base) {
  string result = "";
  while(num) {
    int currDigit = num % base;
    result = NUMS[currDigit] + result;
    num /= base;
  }
  return result;
}

bool isPld(const string& s) {
  int l = s.length();
  for(int i = 0; i < l/2; ++i)
    if(s[i] != s[l-1-i])
      return false;
  return true;
}
