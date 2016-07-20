// Xiaoyan Wang 12/25/2015
#include <iostream>
using namespace std;

int main() {
  string scores[] = {"F", "D", "C", "B", "A", "A++"};
  int grade;
  cin >> grade;
  string lettergrade = ((grade < 60) ? scores[0] :
			scores[(grade-50)/10]) + ((grade == 100) ? "" :
						  (grade % 10 > 7) ? "+":
						  (grade % 10 < 3) ? "-" : "");
  cout << lettergrade << endl;

  return 0;
}
