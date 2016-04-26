/*
ID: skyline12
PROG: ariprog
LANG: C++11
*/
// Xiaoyan Wang 4/25/2016
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;

struct Sequence {
  int a;
  int b;
};

bool compseqs(const Sequence& seq1, const Sequence& seq2);

int main() {
  std::ifstream fin("ariprog.in");
  std::ofstream fout("ariprog.out");
  // N: length of progressions
  // M: upper bound of the bisquares to search
  int N, M;
  fin >> N >> M;
  fin.close();

  // the following part is used to calculate bisquares
  // bisq: short for bisquares
  // the maximum bisquare is when p = q = M
  // such that p^2 + q^2 = 2*M^2
  int limit = 2*M*M;
  vector<bool> bisq(limit+1, false);
  for(int i = 0; i <= M; ++i)
    for(int j = 0; j <= M; ++j)
      bisq[i*i+j*j] = true;
  
  // the actual problem-solving part
  // a, n, b corresponds to the ones use in
  // arithmatic progression: a + nb
  vector<Sequence> seqs;
  for(int a = 0; a <= limit; ++a) {
    if(!bisq[a])
      continue;
    for(int b = 1; a+(N-1)*b <= limit; ++b) {
      int n = 1;
      int currVal = a + b;
      for(; n < N && bisq[currVal]; ++n)
	currVal += b;
      if(n == N) {
	Sequence temp = {a, b};
	seqs.push_back(temp);
      }
    }
  }

  if(seqs.size() == 0)
    fout << "NONE\n";
  else {
    std::sort(seqs.begin(), seqs.end(), compseqs);
    for(const Sequence& seq : seqs)
      fout << seq.a << ' ' << seq.b << '\n';
  }

  fout << std::flush;
  fout.close();

  return 0;
}

bool compseqs(const Sequence& seq1, const Sequence& seq2) {
  if(seq1.b == seq2.b)
    return seq1.a < seq2.a;
  return seq1.b < seq2.b;
}
