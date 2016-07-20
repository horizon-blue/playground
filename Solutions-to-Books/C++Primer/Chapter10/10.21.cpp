// Exercise 10.21
// Write a lambda that captures a local int variable and decrements that
// variable until it reaches 0. Once the variable is 0 additional calls
// should no longer decrement the variable. The lambda should return a
// bool that indicates whether the captured variable is 0.
// Xiaoyan Wang 7/20/2016
#include <iostream>
using std::cin;
using std::cout;

int main() {
  int i;
  cout << "Enter a number: ";
  cin >> i;
  auto decre = [&i]{return !(i ? i-- : i);};

  bool iszero = decre();

  cout << "i " << (iszero ? "is" : "isn't")
       << " zero. After calling lambda, i = " << i << std::endl;

  return 0;
}
