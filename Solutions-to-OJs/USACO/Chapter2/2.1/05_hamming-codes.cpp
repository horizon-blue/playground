/*
ID: skyline12
PROG: hamming
LANG: C++11
*/
// Xiaoyan Wang 5/10/2016
#include <fstream>
#include <vector>
using std::vector;

int N, B, D;
vector<int> result;

bool qualify(int num);
bool farenough(int a, int b);

int main() {
  std::ifstream fin("hamming.in");
  std::ofstream fout("hamming.out");
  fin >> N >> B >> D;
  fin.close();

  int maximum = 1 << B+1;
  result.reserve(N);
  result.push_back(0);
  
  // generate the integers from 0 to maximum
  for(int i = 1; i < maximum && result.size() < N; ++i)
    if(qualify(i))
      result.push_back(i);

  fout << result[0];
  
  // print the result
  for(int i = 1; i < N; ++i) {
    if(i % 10 == 0)
      fout << '\n';
    else
      fout << ' ';
    fout << result[i];
  }
  fout << std::endl;
  
  fout.close();

  return 0;
}

inline bool qualify(int num) {
  for(int r : result)
    if(!farenough(r, num))
      return false;
  return true;
}

inline bool farenough(int a, int b) {
  int diff = a ^ b;
  // stripping off the lowest bit and test it for D-1 times
  for(int j = 0; j < D; ++j) {
    if(!diff)
      return false;
    diff &= diff-1;
  }
  return true;
}
