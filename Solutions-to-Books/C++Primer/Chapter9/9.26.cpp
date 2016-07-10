// Exercise 9.26
// Using the following definition of ia, copy ia into
// a vector and into a list. Use the single-iterator
// form of erase to remove the elements with odd values
// from your list and the even values from your vector
// int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
// Xiaoyan Wang 7/7/2016
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> ivec;
  list<int> ilst;

  ivec.assign(begin(ia), end(ia));
  ilst.assign(begin(ia), end(ia));

  cout << "ia =";
  for(int num : ia)
    cout << ' ' << num;
  cout << endl;

  cout << "ivec =";
  for(int num : ivec)
    cout << ' ' << num;
  cout << endl;

  cout << "ilst =";
  for(int num : ilst)
    cout << ' ' << num;
  cout << endl;

  // remove odd value from list
  for(auto it = ilst.begin(); it != ilst.end();)
    if(*it % 2)
      it = ilst.erase(it);
    else
      ++it;

  // remove even value from vector
  for(auto it = ivec.begin(); it != ivec.end();)
    if(!(*it % 2))
      it = ivec.erase(it);
    else
      ++it;

  cout << "After erasing:" << endl;

  cout << "ia =";
  for(int num : ia)
    cout << ' ' << num;
  cout << endl;

  cout << "ivec =";
  for(int num : ivec)
    cout << ' ' << num;
  cout << endl;

  cout << "ilst =";
  for(int num : ilst)
    cout << ' ' << num;
  cout << endl;

  return 0;
}
