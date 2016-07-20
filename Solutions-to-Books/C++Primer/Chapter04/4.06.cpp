#include <iostream>
using namespace std;

int main() {
  cout << "Enter an integer: ";
  int num;
  cin >> num;
  if(num % 2)
    cout << "The number is odd.\n";
  else
    cout << "The number is even.\n";
  return 0;
}
