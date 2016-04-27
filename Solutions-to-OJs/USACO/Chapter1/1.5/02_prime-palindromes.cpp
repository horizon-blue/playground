/*
ID: skyline12
PROG: pprime
LANG: C++11
*/
// Xiaoyan Wang 4/26/2016
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using std::sqrt;
using std::sort;
using std::vector;

vector<int> palind;
int a, b;

int index(int num);
bool inrange(int num);

void find_palindromes();
// vector<bool> checked;
// void mark_primes();
// void check(int p);

bool isPrime(int num);

int main() {
  std::ifstream fin("pprime.in");
  std::ofstream fout("pprime.out");
  fin >> a >> b;
  fin.close();

  // this is about the maximum number of qualifying
  // palinds I get after trying the largest range
  palind.reserve(800);
  
  find_palindromes();

  // checked = vector<bool>(b/3, false);
  // mark_primes();
  sort(palind.begin(), palind.end());

  for(int num : palind)
    if(isPrime(num))
      fout << num << '\n';
  fout << std::flush;
  fout.close();

  return 0;
}

inline int index(int num) {
  return num-a;
}

inline bool inrange(int num) {
  return num >= a && num <= b;
}

// a ridicuously huge function to mark all palindromes
// in range as true
// skip the ones that end with 2 to save time (since
// any number ends with 2 is divisible by 2, which means
// it is not a prime (2 itself is an exception, but 2 is
// not in our range)
void find_palindromes() {
  for(int d1 = 1; d1 <= 9; d1+=2) {
    if(inrange(d1) && isPrime(d1)) 
      palind.push_back(d1);
    if(inrange(d1*10+d1) && isPrime(d1*10+d1))
      palind.push_back(d1*10+d1);
    for(int d2 = 0; d2 <= 9; ++d2) {
      if(inrange(d1*100+d2*10+d1) && isPrime(d1*100+d2*10+d1))
	palind.push_back(d1*100+d2*10+d1);
      if(inrange(d1*1000+d2*100+d2*10+d1) && isPrime(d1*1000+d2*100+d2*10+d1))
	palind.push_back(d1*1000+d2*100+d2*10+d1);
      for(int d3 = 0; d3 <= 9; ++d3) {
	if(inrange(d1*10000+d2*1000+d3*100+d2*10+d1) && isPrime(d1*10000+d2*1000+d3*100+d2*10+d1))
	  palind.push_back(d1*10000+d2*1000+d3*100+d2*10+d1);
	if(inrange(d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1)
	   && isPrime(d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1))
	  palind.push_back(d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1);
	for(int d4 = 0; d4 <= 9; ++d4) {
	  if(inrange(d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1) &&
	     isPrime(d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1))
	    palind.push_back(d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1);
	  if(inrange(d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1) &&
	     isPrime(d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1))
	    palind.push_back(d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1);
	}
      }
    }
  }
}

// void mark_primes() {
//   // since multiples of 2 have already been elminated
//   for(int p = 2; p < b/3; p+=p)
//     checked[p];
//   for(int p = 3; p < b/3; p+=2)
//     check(p);
// }

// void check(int p) {
//   if(checked[p])
//     return;
//   int curr = p;
//   while(curr <= b) {
//     curr += p;
//     if(curr <= b/3)
//       checked[curr] = true;
//     if(inrange(curr))
//       valid[index(curr)] = false;

//   }
// }

bool isPrime(int num) {
  int limit = sqrt(num) + 1;
  for(int i = 3; i <= limit; ++i)
    if(num%i == 0)
      return false;
  return true;
}
