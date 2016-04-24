/*
ID: skyline12
PROG: transform
LANG: C++11
*/
// Xiaoyan Wang 4/21/2016
#include <fstream>
#include <vector>
using std::vector;
using std::ifstream;
using std::ofstream;
typedef vector<vector<char> > square;

bool rotate90(const square &sq1, const square &sq2);
bool rotate180(const square &sq1, const square &sq2);
bool rotate270(const square &sq1, const square &sq2);
bool reflect(const square &sq1, const square &sq2);
bool combination(const square &sq1, const square &sq2);
bool nochange(const square &sq1, const square &sq2);
int determinetype(const square &sq1, const square &sq2);


int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");

  int N;
  fin >> N;

  // old ane new squarse
  square sq1(N, vector<char>(N));
  square sq2(N, vector<char>(N));
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      fin >> sq1[i][j];
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      fin >> sq2[i][j];

  fout << determinetype(sq1, sq2) << std::endl;

  fin.close();
  fout.close();
  
  return 0;
}

int determinetype(const square &sq1, const square &sq2) {
  if(rotate90(sq1, sq2))
    return 1;
  if(rotate180(sq1, sq2))
    return 2;
  if(rotate270(sq1, sq2))
    return 3;
  if(reflect(sq1, sq2))
    return 4;
  if(combination(sq1, sq2))
    return 5;
  if(nochange(sq1, sq2))
    return 6;
  return 7;
}

bool rotate90(const square &sq1, const square &sq2) {
  int n = sq1.size();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(sq2[j][n-1-i] != sq1[i][j])
	return false;
  return true;
}

bool rotate180(const square &sq1, const square &sq2) {
  int n = sq1.size();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(sq2[n-1-i][n-1-j] != sq1[i][j])
	return false;
  return true;
}

bool rotate270(const square &sq1, const square &sq2) {
  int n = sq1.size();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(sq2[n-1-j][i] != sq1[i][j])
	return false;
  return true;
}

bool reflect(const square &sq1, const square &sq2) {
  int n = sq1.size();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(sq2[i][n-1-j] != sq1[i][j])
	return false;
  return true;
}

bool combination(const square &sq1, const square &sq2) {
  int n = sq1.size();
  square temp(n, vector<char>(n));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      temp[i][n-1-j] = sq1[i][j];

  return rotate90(temp, sq2) || rotate180(temp, sq2) ||
    rotate270(temp, sq2);
}

bool nochange(const square &sq1, const square &sq2) {
  int n = sq1.size();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(sq2[i][j] != sq1[i][j])
	return false;
  return true;
}
