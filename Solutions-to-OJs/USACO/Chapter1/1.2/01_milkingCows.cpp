/*
ID: skyline12
PROG: milk2
LANG: C++11
*/
// Xiaoyan Wang 4/21/2016
#include <fstream>
#include <algorithm>
#include <vector>
using std::max;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istream;

const unsigned int MILKPERIOD = 1000000;


struct MilkTime {
  unsigned int start;
  unsigned int end;
};

istream& operator >>(istream& input, MilkTime& mkt);
bool compareMkt(const MilkTime& mkt1,const MilkTime& mkt2);

int main() {
  ofstream fout("milk2.out");
  ifstream fin("milk2.in");
  
  int N; // number of cows being milked
  fin >> N;

  vector<MilkTime> mkts(N);
  for(int i = 0; i < N; ++i)
    fin >> mkts[i];

  std::sort(mkts.begin(), mkts.end(), compareMkt);

  // the status at given second
  bool isMilking[MILKPERIOD] = {};
  
  // store the milk information in a bool array
  unsigned int currTime = 0;
  for(const MilkTime& mkt : mkts) {
    if(mkt.start >= currTime) {
      for(int i = mkt.start; i < mkt.end; ++i)
	isMilking[i] = true;
      currTime = mkt.end;
    }
    else if(mkt.end > currTime) {
      for(int i = currTime; i < mkt.end; ++i)
	isMilking[i] = true;
      currTime = mkt.end;
    }
  }

  // maximum continuous & discontinuous time
  unsigned int maxCont = 0, maxDiscont = 0;
  unsigned int begTime = 0, endTime = 0;
  bool beginFirst = false; // to rule out the first discont
  bool currStatus = isMilking[0];
  currTime = 0;
  for(;currTime < MILKPERIOD; ++currTime) {
    if(isMilking[currTime] != currStatus) {
      // end of a marking period 
      endTime = currTime;
      if(currStatus) {
	beginFirst = true;
	maxCont = max(maxCont, endTime - begTime);
      }
      else {
	if(beginFirst)
	  maxDiscont = max(maxDiscont, endTime - begTime);
      }
      // beginning of a new marking period
      begTime = currTime;
      currStatus = isMilking[currTime];
    }
  }

  fout << maxCont << ' ' << maxDiscont << std::endl;

  return 0;
}

istream& operator >>(istream& input, MilkTime& mkt) {
  input >> mkt.start >> mkt.end;
  return input;
}

inline bool compareMkt(const MilkTime& mkt1,const MilkTime& mkt2) {
  if(mkt1.start == mkt2.start)
    return mkt1.end < mkt2.end;
  return mkt1.start < mkt2.start;
}
