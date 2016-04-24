/*
ID: skyline12
PROG: gift1
LANG: C++11
*/
#include <string>
#include <fstream>
using namespace std;

string people[10] = {""};

int id(string person, int np) {
  for(int i = 0; i < np; ++i)
    if(people[i] == person)
      return i;
}
  
int main() {
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int np;
  int moneyGive[10] = {0};
  int moneyReceive[10] = {0};
  fin >> np;
  for(int i = 0; i < np; ++i)
    fin >> people[i];

  string person;
  int mG, nR;
  while(fin >> person) {
    fin >> mG >> nR;
    if(nR != 0) {
      int pergift = mG/nR;
      moneyGive[id(person, np)] += mG - mG%nR;
      for(int i = 0; i < nR; ++i) {
	string receiver;
	fin >> receiver;
	moneyReceive[id(receiver, np)] += pergift;
      }
    }
  }
  
  for(int i = 0; i < np; ++i)
    fout << people[i] << ' ' << moneyReceive[i] - moneyGive[i] << endl;

  return 0;
} 
