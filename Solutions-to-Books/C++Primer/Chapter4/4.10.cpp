// Write the ondition for a while loop that would read
// ints from the standard input and stop when the
// value read is equal to 42
// Xiaoyan Wang 12/4/2015
#include <iostream>
using namespace std;

int main() {
  int temp;
  while(cin >> temp && temp != 42);
  return 0;
}
