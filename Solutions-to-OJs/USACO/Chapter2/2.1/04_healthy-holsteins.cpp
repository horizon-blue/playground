/*
ID: skyline12
PROG: holstein
LANG: C++11
*/
// Xiaoyan Wang 5/10/2016
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;
typedef vector<int> Feed;

struct Solution{
  int size;
  vector<int> sol;
  Solution() = default;
  Solution(int s, const vector<bool>& so): size(s) {
    sol.reserve(size);
    for(int i = 0; i < so.size(); ++i)
      if(so[i])
	sol.push_back(i+1);
  }
};

Feed requirement;
vector<Feed> feedtypes;
vector<bool> pairs;
vector<Solution> result;
int V, G;

void pairing(int previous, int numfeed);
bool isworking();
bool compare(const Solution& s1, const Solution& s2);

int main() {
  std::ifstream fin("holstein.in");
  std::ofstream fout("holstein.out");
  
  // read the input from file
  fin >> V;
  requirement = Feed(V);
  for(int i = 0; i < V; ++i)
    fin >> requirement[i];
  fin >> G;
  feedtypes = vector<Feed>(G, Feed(V));
  for(int i = 0; i < G; ++i)
    for(int j = 0; j < V; ++j)
      fin >> feedtypes[i][j];
  fin.close();

  // // TESTing
  // for(int i = 0; i < G; ++i) {
  //   for(int j = 0; j < V; ++j)
  //     fout << feedtypes[i][j] << ' ';
  //   fout << '\n';
  // }

  pairs = vector<bool>(G, false);
  pairing(-1, 0);

  auto final = std::min_element(result.begin(),
				    result.end(), compare);
  fout << final->size;
  for(int i = 0; i < final->size; ++i)
    fout << ' ' << final->sol[i];
  fout << std::endl;
  
  fout.close();

  return 0;
}

// pairing the feed until numfeed reach the maximum
void pairing(int previous, int numfeed) {
  if(numfeed == G || previous == G-1)
    return;
  for(int i = previous + 1; i < G; ++i)
    if(!pairs[i]) { // if ith feed is not use
      pairs[i] = true;
      if(isworking()) // if current pairs work, stop searching on this branch
	result.push_back(Solution(numfeed+1, pairs)); 
      else
	pairing(i, numfeed+1);
      pairs[i] = false;
    }
}

bool isworking() {
  Feed total(V, 0);
  for(int i = 0; i < G; ++i)
    if(pairs[i])
      for(int j = 0; j < V; ++j)
	total[j] += feedtypes[i][j];

  for(int j = 0; j < V; ++j)
    if(total[j] < requirement[j])
      return false;

  return true;
}

bool compare(const Solution& s1, const Solution& s2) {
  if(s1.size == s2.size)
    for(int i = 0; i < s1.size; ++i)
      if(s1.sol[i] == s2.sol[i])
	continue;
      else
	return s1.sol[i] < s2.sol[i];
  return(s1.size < s2.size);
}
