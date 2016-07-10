// Xiaoyan Wang 12/21/2015
#include <iostream>
using std::cout;
using std::endl;

int main() {
  int sum = 0, val = 1;
  while (val <= 10)
    sum += val, ++val;
  cout << "Sum of 1 to 10 inclusive is "
       << sum << endl;

  return 0;
}
