#include <initializer_list>
#include <iostream>
using namespace std;

int sum(initializer_list<int> li) {
  int sum = 0;
  for(auto beg = li.begin(); beg != li.end(); ++beg)
    sum += *beg;
  return sum;
}

int main() {
  int s = sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  cout << "The sum of 1 to 10 is " << s << "." << endl;
  return 0;
}
