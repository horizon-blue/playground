// Xiaoyan Wang 12/25/2015
#include <iostream>
#include <string>
using namespace std;

int main() {
  string scores[] = {"F", "D", "C", "B", "A", "A++"};
  int grade;
  cin >> grade;
  string lettergrade;
  if (grade < 60)
    lettergrade = scores[0];
  else {
    lettergrade = scores[(grade-50)/10];
    if (grade % 10 > 7)
      lettergrade += '+';
    else if (grade % 10 < 3 && grade != 100)
      lettergrade += '-';
  }

  cout << lettergrade << endl;
  return 0;
}
