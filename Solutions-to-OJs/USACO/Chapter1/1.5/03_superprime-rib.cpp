/*
ID: skyline12
PROG: sprime
LANG: C++11
*/
// Xiaoyan Wang 4/26/2016
#include <fstream>
#include <vector>
using std::vector;

// the only possible digits to start with
const vector<int> PRE = {2, 3, 5, 7};
// the only possible digits to end with
const vector<int> POST = {1, 3, 7, 9};
vector<int> ribs;

bool isPrime(int num);
void find_ribs(int currL, const int length, int val);

int main() {
  std::ifstream fin("sprime.in");
  std::ofstream fout("sprime.out");
  int length;
  fin >> length;
  fin.close();

  for(int i = 0; i < 4; ++i)
    find_ribs(1, length, PRE[i]);

  for(int r : ribs)
    fout << r << '\n';
  fout << std::flush;
  
  fout.close();
  return 0;
}

bool isPrime(int num) {
  if(num == 1)
    return false;
  for(int i = 2; i*i <= num; ++i)
    if(num%i == 0)
      return false;
  return true;
}

void find_ribs(int currL, const int length, int val) {
  if(!isPrime(val))
    return;
  if(currL == length) {
    ribs.push_back(val);
    return;
  }
  for(int i = 0; i < 4; ++i)
    find_ribs(currL+1, length, val*10+POST[i]);
}
