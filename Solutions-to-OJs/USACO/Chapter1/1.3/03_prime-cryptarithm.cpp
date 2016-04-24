/*
ID: skyline12
PROG: crypt1
LANG: C++11
*/
// Xiaoyan Wang 4/23/2016
#include <vector>
#include <fstream>
using std::vector;
using std::endl;

bool isValid(int num, const vector<bool>& exists, int d);

int main() {
  std::ifstream fin("crypt1.in");
  std::ofstream fout("crypt1.out");

  // the part that read the input
  int N;
  fin >> N;

  vector<int> digits;
  // "exists" make it faster in checking validity
  vector<bool> exists(10, false);
  
  for(int i = 0; i < N; ++i) {
    int temp;
    fin >> temp;
    digits.push_back(temp);
    exists[temp] = true;
  }

  // loop through each digit to check validity
  int count = 0;
  // using 3 loops to check the first number abc
  for(int a : digits) {
    if(a == 0)
      continue;
    for(int b : digits) {
      for(int c: digits) {
	// check the digit of second number one by one
	for(int d: digits) {
	  if(d == 0)
	    continue;
	  int num1 = a*100 + b*10 + c;
	  int num2p1 = num1 * d;
	  if(isValid(num2p1, exists, 3)) {
	    for(int e: digits) {
	      int num2p2 = num1 * e;
	      if(isValid(num2p2, exists, 3)) {
		int result = num2p1*10 + num2p2;
		if(isValid(result, exists, 4))
		  ++count;
	      }
	    }
	  }
	}
      }
    }
  }

  fout << count << endl;
  
  
  fin.close();
  fout.close();

  return 0;
}

bool isValid(int num, const vector<bool>& exists, int d) {
  int digits = 0;
  while(num) {
    ++digits;
    if(!exists[num % 10])
      return false;
    num /= 10;
  }
  if(digits != d)
    return false;
  return true;
}
       
