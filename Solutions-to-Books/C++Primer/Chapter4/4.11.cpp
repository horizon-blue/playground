// Write an expression that tests four 
// values, a, b, c, and d, and ensures
// that a is greater than b, which is
// greater thant c, which is greater than
// d
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a > b && b > c && c > d)
    cout << "True" << endl;
  else
    cout << "False" << endl;
  return 0;
}
