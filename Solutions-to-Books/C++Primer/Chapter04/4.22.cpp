// Extend the program that assigned high pass,
// pass, and fail grades to also assign low
// pass for grades between 60 and 75 inclusive.
// Xiaoyan Wang 12/14/2015
#include <iostream>
using namespace std;

int main() {
  int grade;
  cout << "Enter a grade for the student: \n";
  cin >> grade;
  cout << ((grade > 90) ? "high pass"
	   : (grade > 75) ? "pass"
	   : (grade > 60) ? "low pass"
	   : "fail") << endl;
  return 0;
}
