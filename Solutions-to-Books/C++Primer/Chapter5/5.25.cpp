// Xiaoyan Wang 12/27/2015
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  int a, b;
  cout << "Enter two integers: " << endl;
  while(cin >> a >> b) {
    try {
      if(b == 0)
	throw runtime_error("Divisor cannot be zero.");
      cout << a/b << endl;
      break;
    } catch (runtime_error err) {
      cout << err.what() << endl
	   << "Try again? (y/n)" << endl;
      char c;
      cin >> c;
      if(!cin || c == 'n')
	break;
    }
  }

  return 0;
}
