/*
ID: skyline12
PROG: combo
LANG: C++11
*/
// Xiaoyan Wang 4/24/2016
#include <fstream>
#include <algorithm>
using std::min;
using std::endl;

int numoverlap(int a, int b, int limit);

int range(int a, int b, int limit);

int main() {
  std::ifstream fin("combo.in");
  std::ofstream fout("combo.out");

  int N;
  int j1, j2, j3;
  int m1, m2, m3;
  fin >> N >> j1 >> j2 >> j3 >> m1 >> m2 >> m3;

  // if N <= 5, then any combination would open the lock
  if(N <= 5) {
    fout << N*N*N << endl;
    return 0;
  }

  // the total number of combination is
  // 2*5^3, including overlapping ones
  int total = 250;

  int overlap1 = numoverlap(j1, m1, N);
  int overlap2 = numoverlap(j2, m2, N);
  int overlap3 = numoverlap(j3, m3, N);

  total -= overlap1*overlap2*overlap3;

  fout << total << endl;

  fin.close();
  fout.close();
  
  return 0;
}
  
inline int numoverlap(int a, int b, int limit) {
  if(a > b)
    return numoverlap(b, a, limit);
  int over1 = 5-b+a;
  int over2 = 5-limit+b-a;
  if(over1 > 0 && over2 > 0)
    return over1 + over2;
  if(over1 > 0)
    return over1;
  if(over2 > 0)
    return over2;
  return 0;
}
