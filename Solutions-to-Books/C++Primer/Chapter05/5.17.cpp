// Xiaoyan Wang 12/26/2015
#include <iostream>
#include <vector>
using std::cin; using std:: cout; using std::endl;
using std::vector;

bool isPrefix(vector<int> ivec1, vector<int> ivec2) {
  bool isPre = true;
  for(int i = 0; i < ((ivec1.size()<ivec2.size())?ivec1.size():ivec2.size()); ++i)
    if(ivec1[i] != ivec2[i]) {
      isPre = false;
      break;
    }
  return isPre;
}

int main() {
  vector<int> ivec1, ivec2;
  cout << "Enter the number of elements in ivec1 and ivec2: ";
  int num1, num2;
  cin >> num1 >> num2;
  cout << "Enter the elements of ivec1:" << endl;
  int temp;
  for(int i = 0; i < num1; ++i) {
    cin >> temp;
    ivec1.push_back(temp);
  }
  cout << "Enter the elements of ivec2:" << endl;
  for(int i = 0; i < num2; ++i) {
    cin >> temp;
    ivec2.push_back(temp);
  }
  
  if(isPrefix(ivec1, ivec2))
    cout << "true" << endl;
  else
    cout << "false" << endl;

  return 0;
}
