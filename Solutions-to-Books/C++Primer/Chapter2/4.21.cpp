// Write a program to use a conditional operator
// to find the elements in a vector<int> that
// have odd value and double the value of each
// such element.
// Xiaoyan Wang 12/14/2015
#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> ivec(10);
  for(int i = 0; i < 10; ++i)
    ivec[i] = i+1;
  for(auto iter = ivec.begin(); iter != ivec.end(); ++iter)
    *iter = ((*iter) % 2 ? (*iter) * 2 : *iter);
  for(int i : ivec)
    cout << i << endl;
  return 0;
}
