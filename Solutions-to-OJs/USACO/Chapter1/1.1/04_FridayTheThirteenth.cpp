/*
ID: skyline12
PROG: friday
LANG: C++11
*/
#include <fstream>
using namespace std;

bool isLeap(int year) {
  if(year % 4)
    return false;
  if(!(year % 100) && (year % 400))
    return false;
  return true;
}

int getDays(int month, int year) {
  if(month == 0)
    month = 12;
  if(month == 2)
    if(isLeap(year))
      return 29;
    else
      return 28;
  if(month <= 7)
    return ((month % 2) ? 31 : 30);
  return((month % 2) ? 30 : 31);
}

  
int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int years;
  fin >> years;

  int dayCount[7] = {0};
  int previous = 4;

  for(int i = 1900; i < 1900 + years; ++i)
    for(int j = 0; j < 12; ++j) {
      int day = (previous + getDays(j, i) % 7) % 7;
      ++dayCount[day];
      previous = day;
    }

  for(int i = 0; i < 6; ++i)
    fout << dayCount[i] << ' ';

  fout << dayCount[6] << endl;

  return 0;
} 
