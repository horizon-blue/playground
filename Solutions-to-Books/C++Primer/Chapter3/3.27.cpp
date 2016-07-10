// Tryout part(c)
// Xiaoyan Wang 11/18/2015
#include <iostream>
using namespace std;

int txt_size() {
  return 10;
}

int main () {
  int ia[txt_size()];
  for(int i = 0; i < txt_size(); ++i)
    cout << ia[i] << endl;
  return 0;
}
