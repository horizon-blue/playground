/*
ID: skyline12
PROG: frac1
LANG: C++11
*/
// Xiaoyan Wang 5/5/2016
#include <fstream>
#include <algorithm>
#include <vector>
using std::vector;

struct Fraction {
  int numer;
  int denom;
};

int N; // the maximum denom
vector<Fraction> fvec;

std::ostream& operator<<(std::ostream& out, const Fraction& f);
void fracGenerator();
int gcd(int a, int b); // help decide wheter the fraction is reduced
bool fracCompare(const Fraction& f1, const Fraction& f2);

int main() {
  std::ifstream fin("frac1.in");
  std::ofstream fout("frac1.out");
  fin >> N;
  fin.close();

  // reserve more than necessary space to avoid reallocation
  fvec.reserve(N*(N+1)/2);
  fracGenerator();

  std::sort(fvec.begin(), fvec.end(), fracCompare);

  for(auto f : fvec)
    fout << f << '\n';
  fout << std::flush;

  fout.close();

  return 0;
}
  
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
  out << f.numer << '/' << f.denom;
  return out;
}

void fracGenerator() {
  fvec.push_back({0, 1});
  for(int d = 1; d <= N; ++d)
    for(int n = 1; n < d; ++n)
      if(gcd(d, n) == 1) // if the fraction is reduced
	fvec.push_back({n, d});
  fvec.push_back({1, 1});
}

int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

bool fracCompare(const Fraction& f1, const Fraction& f2) {
  return f1.numer*f2.denom < f1.denom*f2.numer;
}
