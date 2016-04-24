/*
ID: skyline12
PROG: dualpal
LANG: C++11
*/
// Xiaoyan Wang 4/23/2016
#include <fstream>
#include <string>
#include <climits>
using std::to_string;
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

bool isPld(const string& s);
string convertBase(int num, int base);
const string NUMS = "0123456789ABCDEFGHIJ";

int main() {
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");

  int N, S;
  fin >> N >> S;

  for(long num = S+1; num < LONG_MAX && N; ++num) {
    int count = 0;
    for(int base = 2; base <= 10; ++base) {
      if(isPld(convertBase(num, base)))
	++count;
      if(count == 2) {
	fout << num << endl;
	--N;
	break;
      }
    }
  }
  
  fin.close();
  fout.close();
  return 0;
}

string convertBase(int num, int base) {
  if(base == 10)
    return to_string(num);
  
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
