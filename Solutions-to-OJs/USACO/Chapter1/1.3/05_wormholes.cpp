/*
ID: skyline12
PROG: wormhole
LANG: C++11
*/
// Xiaoyan Wang 4/24/2016
#include <fstream>
#include <vector>
#include <algorithm>
using std::endl;
using std::vector;

struct Wormhole {
  int x;
  int y;
};

// a helper function to order wormhole according to their y values
void order_y_position(const vector<Wormhole>& wvec, int size, vector<int>& right_one);
int numSolution(int size, vector<int>& pairs, const vector<int>& right_one);
bool goodpair(int size, const vector<int>& pairs, const vector<int>&right_one);

int main() {
  std::ifstream fin("wormhole.in");
  std::ofstream fout("wormhole.out");

  int N; // number of worm holes
  fin >> N;

  vector<Wormhole> wvec(N);
  
  for(int i = 0; i < N; ++i)
    fin >> wvec[i].x >> wvec[i].y;

  vector<int> right_one(N, -1);
  vector<int> pairs(N, -1);

  order_y_position(wvec, N, right_one);
  
  int solution = numSolution(N, pairs, right_one);  

  fout << solution << endl;
  
  fin.close();
  fout.close();

  return 0;
}

int numSolution(int size, vector<int>& pairs, const vector<int>& right_one) {
  int totalresult = 0;
  // use recursion to pair all wormholes
  int first = 0;
  // locate the first unpaired wormhole
  for(; first < size; ++first)
    if(pairs[first] == -1)
      break;

  // if all wormholes have been paired
  if(first == size)
    return goodpair(size, pairs, right_one);

  // find the other unpaired wormhole
  for(int second = first + 1; second < size; ++second) {
    if(pairs[second] == -1) {
      pairs[first] = second;
      pairs[second] = first;
      // call numSolution itself and use recursion to pair
      // the rest of the wormholes
      totalresult += numSolution(size, pairs, right_one);
      // clear the current pair to pair first with a new
      // second
      pairs[first] = pairs[second] = -1;
    }
  }
  return totalresult;
}

void order_y_position(const vector<Wormhole>& wvec, int size, vector<int>& right_one) {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      // the case i == j would be ruled out by the second condition
      if(wvec[j].y == wvec[i].y && wvec[j].x > wvec[i].x)
	if(right_one[i] == -1)
	  right_one[i] = j;
	else if(wvec[right_one[i]].x > wvec[j].x) // if current right_one is further from x
	  right_one[i] = j;
    }
  }
}


bool goodpair(int size, const vector<int>& pairs, const vector<int>&right_one) {
  // try going from each of the wormhole
  for(int i = 0; i < size; ++i) {
    vector<bool> visited(12, false);
    for(int pos = i; pos != -1; pos = right_one[pairs[pos]]) {
      if(visited[pos] == true)
	return true;
      visited[pos] = true;
    }
  }
  return false;
}
