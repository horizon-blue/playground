/*
ID: skyline12
PROG: numtri
LANG: C++11
*/
// Xiaoyan Wang 4/26/2016
// Idea:
// go down each row of the triangle and memorize
// the maximum value at each column
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;
using std::max;

// to store the triangle from input
vector <vector<int> >  triangle;
// to store the max value of each column
vector<int> maxValues;
// R: number of rows
// store the information from fin into the vector
int R;

void solve();
void solve(int r);

int main() {
  std::ifstream fin("numtri.in");
  std::ofstream fout("numtri.out");

  fin >> R;
  triangle = vector<vector<int> >(R, vector<int>(R));
  for(int i = 0; i < R; ++i)
    for(int j = 0; j <= i; ++j)
      fin >> triangle[i][j];
  fin.close();
  maxValues = vector<int>(R, 0);

  solve();  

  // find the maximum value of the final row
  int max = 0;
  for(int num : maxValues)
    if(num > max)
      max = num;

  fout << max << std::endl;
  fout.close();

  return 0;
}

void solve() {
  maxValues[0] = triangle[0][0];
  for(int r = 1; r < R; ++r)
    solve(r);
}

void solve(int r) {
  vector<int> previous = maxValues;
  maxValues[0] = previous[0] + triangle[r][0];
  for(int c = 1; c < r; ++c)
    maxValues[c] = max(previous[c-1], previous[c])
      + triangle[r][c];
  maxValues[r] = previous[r-1] + triangle[r][r];
}
