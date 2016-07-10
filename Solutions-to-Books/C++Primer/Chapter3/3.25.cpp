// Rewrite the grade clustering program
// on page 104 using iterators instead
// of subscripts
// Xiaoyan Wang 11/18/2015
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<unsigned> scores(11, 0);
  unsigned grade;
  auto selector = scores.begin();

  while(cin>>grade) {
    if (grade <= 100)
      ++*(selector+grade/10);
  }

  cout << endl;

  for(auto i = scores.begin(); i != scores.end(); ++i)
    cout << *i << ' ';

  cout << endl;

  return 0;
}
