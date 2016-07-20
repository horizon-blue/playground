// Exercise 9.50
// Write a program to process a vector<string>
// whose elements represent ingegral values. Produce
// the sum of all the elements in the vector.
// Change the program so that is sumes of strings
// that represent floating-point values.
// Xiaoyan Wang 7/14/2016
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int sum_of_int(const vector<string>& svec) {
  int sum = 0;
  for(const string& s : svec)
    sum += stoi(s);
  return sum;
}

double sum_of_double(const vector<string>& svec) {
  double sum = 0;
  for(const string& s : svec)
    sum += stof(s);
  return sum;
}

int main() {
  vector<string> svec = {"123", "1.42", "-102", "3.1415926"};
  cout << "sum_of_int(svec) = " << sum_of_int(svec) << endl;
  cout << "sum_of_double(svec) = " << sum_of_double(svec) << endl;

  return 0;
}
