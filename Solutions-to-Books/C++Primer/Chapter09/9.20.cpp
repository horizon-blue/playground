// Exercise 9.20
// Write a program to cpy elements from a list<int>
// into two deques. The even-valued elements should go
// into one deque and the odd ones into the other.
// Xiaoyan Wang 7/7/2016
#include <iostream>
#include <deque>
#include <list>
using namespace std;

int main() {
  list<int> original;
  deque<int> odd, even;
  for(int temp; cin >> temp; original.push_back(temp));
  for(int num : original)
    if(num % 2)
      odd.push_back(num);
    else
      even.push_back(num);

  cout << "The odd numbers are: ";
  for(int n : odd)
    cout << n << ' ';
  cout << endl;

  cout << "The even numbers are: ";
  for(int n: even)
    cout << n << ' ';
  cout << endl;

  return 0;
}
