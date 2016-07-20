// Xiaoyan Wang 12/27/2015
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  int a, b;
  cout << "Enter two integers: " << endl;
  cin >> a >> b;
  if(b == 0)
    throw runtime_error("Divisor cannot be zero.");
  cout << a/b << endl;

  return 0;
}
