/*
ID: skyline12
PROG: sort3
LANG: C++11
*/
// Xiaoyan Wang 5/5/2016
#include <fstream>
#include <algorithm>
#include <vector>
using std::vector;
using std::min;

int N; // number of values
vector<int> values;
vector<int> num(4, 0);
vector<vector<int> > count(4, vector<int>(4, 0));

void countnum();
int countswap();

int main() {
  std::ifstream fin("sort3.in");
  std::ofstream fout("sort3.out");
  // read the input
  fin >> N;
  values.reserve(N+1);
  values.push_back(0);
  for(int i = 0; i < N; ++i) {
    int temp;
    fin >> temp;
    values.push_back(temp);
    ++num[temp];
  }
  fin.close();

  // process the numbers
  countnum();
  // calculate the number of swaps
  int swap = countswap();

  fout << swap << std::endl;
  fout.close();

  return 0;
}

void countnum() {
  int curr = 1;
  for(int i = 1; i <= 3; ++i) {
    for(int j = curr; j < curr + num[i]; ++j)
      ++count[i][values[j]];
    curr += num[i];
  }
}

int countswap() {
  int swap = 0;
  // count the number of misplaced numbers that could
  // be swapped in a single step
  for(int i = 1; i <= 2; ++i)
    for(int j = i+1; j <= 3; ++j) {
      int temp = min(count[i][j], count[j][i]);
      swap += temp;
      // "swapping" the numbers
      // adding the swapped number into the correct
      // location isn't necessary as i won't use that
      count[i][j] -= temp;
      count[j][i] -= temp;
    }
  // the rest are the values that required swapping twice
  // at this time, there could only be a single type of misplaced
  // value
  if(count[1][2] != 0)
    swap += 2 * count[1][2];
  else if(count[1][3] != 0)
    swap += 2 * count[1][3];

  return swap;
}
