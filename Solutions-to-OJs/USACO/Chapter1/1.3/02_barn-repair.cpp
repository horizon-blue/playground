/*
ID: skyline12
PROG: barn1
LANG: C++11
*/
// Xiaoyan Wang 4/23/2016
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
using std::vector;


int main() {
  std::ifstream fin("barn1.in");
  std::ofstream fout("barn1.out");
  int M, S, C;
  fin >> M >> S >> C;
  int first = S;
  int last = 0;

  // record the status of cow
  vector<bool> isCow(S, false);
  for(int i = 0; i < C; ++i) {
    int cownum;
    fin >> cownum;
    if(cownum < first)
      first = cownum;
    if(cownum > last)
      last = cownum;
    isCow[cownum] = true;
  }

  // check the period where there is no cow
  vector<int> noCow;
  for(int i = first; i <= last; ++i) {
    if(!isCow[i]) {
      int beg = i;
      for(; i <= last; ++i)
	if(isCow[i]) {
	  noCow.push_back(i - beg);
	  break;
	}
    }
  }

  std::sort(noCow.begin(), noCow.end(), std::greater<int>());

  int minNum = last - first + 1;
  for(int i = 0; i < M - 1 && i < noCow.size(); ++i)
    minNum -= noCow[i];

  fout << minNum << std::endl;

  fout.close();
  fin.close();

  return 0;
}
