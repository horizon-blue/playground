/*
ID: skyline12
PROG: skidesign
LANG: C++11
*/
// Xiaoyan Wang 4/24/2016
#include <fstream>
#include <vector>
#include <climits>
using std::vector;

int mincost(const vector<int>& heights,
	    int shortest, int tallest);
int cost(const vector<int>& heights, int low, int high);

int main() {
  std::ifstream fin("skidesign.in");
  std::ofstream fout("skidesign.out");

  int N;
  fin >> N;
  vector<int> heights;
  heights.reserve(N);

  // keep track of the tallest and shortest
  // to reduce the range
  int tallest = 0, shortest = 100;
  for(int i = 0; i < N; ++i) {
    int h;
    fin >> h;
    heights.push_back(h);
    if(h > tallest)
      tallest = h;
    if(h < shortest)
      shortest = h;
  }

  int cost = mincost(heights, shortest, tallest);

  fout << cost << std::endl;
  
  fin.close();
  fout.close();

  return 0;
}

int mincost(const vector<int>& heights,
	    int shortest, int tallest) {
  if(tallest - shortest <= 17)
    return 0;
  int minCost = INT_MAX;
  for(int l = shortest; l + 17 <= tallest; ++l) {
    int currCost = cost(heights, l, l + 17);
    if(currCost < minCost)
      minCost = currCost;
  }
  return minCost;
}

int cost(const vector<int>& heights, int low, int high) {
  int c = 0; // c is short for cost
  for(int h : heights) {
    if(h < low)
      c += (low - h) * (low - h);
    else if(h > high)
      c += (h - high) * (h - high);
  }
  return c;
}
