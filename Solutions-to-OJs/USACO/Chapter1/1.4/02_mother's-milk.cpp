/*
ID: skyline12
PROG: milk3
LANG: C++11
*/
// Xiaoyan Wang 4/26/2016
#include <fstream>
#include <vector>
using std::vector;

void check_states (const vector<int>& bckt,
		   vector<vector<vector<bool> > >& s,
		   vector<int> currPos, int from, int to);
void move_milk (const vector<int>& bckt, vector<int>& currPos,
		int from, int to);

int main() {
  std::ifstream fin("milk3.in");
  
  // capacities of the three buckets
  // 0: A, 1: B, 2: C
  vector<int> bucket(3);
  fin >> bucket[0] >> bucket[1] >> bucket[2];
  fin.close();

  const int LIMIT = bucket[2];

  // a 3-dimensional vector that is used to
  // keep track of the states of the buckets
  vector<vector<vector<bool> > > states
    (LIMIT+1, vector<vector<bool> >
     (LIMIT+1, vector<bool>
      (LIMIT+1, false)));

  // main part of the program
  states[0][0][bucket[2]] = true;
  check_states(bucket, states, {0, 0, bucket[2]}, 2, 0);
  check_states(bucket, states, {0, 0, bucket[2]}, 2, 1);

  // collecting the states of C when A is empty
  vector<bool> c_states(LIMIT+1, false);
  for(int b = 0; b <= LIMIT; ++b)
    for(int c = 0; b+c <= LIMIT; ++c)
      if(states[0][b][c]) // if the state is reachable
	c_states[c] = true;

  // finally, print the result
  std::ofstream fout("milk3.out");
  // to prevent the trailing space
  int c = 0;
  for(; c <= LIMIT; ++c)
    if(c_states[c]) {
      fout << c;
      break;
    }
  for(++c; c <= LIMIT; ++c)
    if(c_states[c])
      fout << ' ' << c;

  fout << std::endl;
  fout.close();
  
  return 0;
}

void check_states (const vector<int>& bckt,
		   vector<vector<vector<bool> > >& s,
		   vector<int> currPos, int from, int to) {
  move_milk(bckt, currPos, from, to);
  // if the state has already been checked
  if(s[currPos[0]][currPos[1]][currPos[2]])
    return;
  s[currPos[0]][currPos[1]][currPos[2]] = true;

  // recursively check the states of the buckets
  for(int f = 0; f < 3; ++f)
    for(int t = 0; t < 3; ++t) {
      if(f == t)
	continue;
      check_states(bckt, s, currPos, f, t);
    }  
}

void move_milk (const vector<int>& bckt, vector<int>& currPos,
		int from, int to) {
  // if there is more milk to fill the bucket
  if(currPos[to] + currPos[from] > bckt[to]) {
    currPos[from] -= bckt[to] - currPos[to];
    currPos[to] = bckt[to];
  }
  else {
    currPos[to] += currPos[from];
    currPos[from] = 0;
  }
}
