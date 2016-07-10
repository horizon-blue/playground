// Exercisde 9.27
// Write a program to find and remove the odd-valued
// elements in a forward_list<int>
// Xiaoyan Wang 7/10/2016
#include <forward_list>
#include <iostream>
using namespace std;

int main() {
  forward_list<int> iflst;
  // Adding elements
  for(int temp; cin >> temp; iflst.push_front(temp));

  cout << "Elements before removal:";
  for(int num : iflst)
    cout << ' ' << num;
  cout << endl;
  
  // Removing odd-valued elements
  auto prev = iflst.before_begin(), curr = iflst.begin();
  while(curr != iflst.end()) {
    if(*curr % 2) // if current value is odd
      curr = iflst.erase_after(prev);
    else
      prev = curr++;
  }

  cout << "Elements after removal:";
  for(int num : iflst)
    cout << ' ' << num;
  cout << endl;

  return 0;
}
