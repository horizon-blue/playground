// Exercise 6.33: Write a recursive function to print
// the contents of a vector
// Xiaoyan Wang 03/05/2016
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVal(vector<int> ivec) {
  if(ivec.empty()) {
    cout << endl;
    return;
  }
  cout << ivec.back() << ' ';
  ivec.pop_back();
  printVal(ivec);
}

int main() {
  vector<int> ivec = {};
  cout << "Enter some numbers: " << endl;
  int temp;
  while(cin >> temp)
    ivec.push_back(temp);

  cout << "The values you entered are: ";
  // call the recursive printing function
  printVal(ivec);

  return 0;
}
