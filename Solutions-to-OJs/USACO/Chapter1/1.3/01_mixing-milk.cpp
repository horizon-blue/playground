/*
ID: skyline12
PROG: milk
LANG: C++11
*/
// Xiaoyan Wang 4/23/16
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;
using std::istream;

struct Farmer {
  int price;
  int supply;
};

bool isCheaper(const Farmer& f1, const Farmer& f2);
istream& operator >>(istream& input, Farmer& f);

int main() {
  std::ifstream fin("milk.in");
  std::ofstream fout("milk.out");

  int demand, numfarmer;
  fin >> demand >> numfarmer;

  vector<Farmer> farmers;
  farmers.reserve(numfarmer);
  
  for(int i = 0; i < numfarmer; ++i) {
    Farmer temp;
    fin >> temp;
    farmers.push_back(temp);
  }

  std::sort(farmers.begin(), farmers.end(), isCheaper);

  int cost = 0;
  for(auto f = farmers.begin(); demand && f != farmers.end(); ++f) {
    if(f -> supply <= demand) {
      cost += (f -> supply) * (f-> price);
      demand -= (f -> supply);
    }
    else {
      cost += demand * (f -> price);
      demand = 0;
    }
  }

  fout << cost << std::endl;

  fin.close();
  fout.close();

  return 0;
}

bool isCheaper(const Farmer& f1, const Farmer& f2) {
  return f1.price < f2.price;
}

istream& operator >>(istream& input, Farmer& f) {
  input >> f.price >> f.supply;
  return input;
}
