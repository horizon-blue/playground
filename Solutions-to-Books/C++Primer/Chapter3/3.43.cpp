// Write three different versions of a 
// program to print the elements of ia.
// One version should use a range for to
// manage the iteration, the other two
// should use an ordinary for loop in one
// case using subscripts and in the other
// using pointers. In all three programs write
// all the types directly. That is, do not
// use a type alias, auto, or decltype to simplify the
// code.
// Xiaoyan Wang 11/21/2015
#include <iostream>
using namespace std;

int main() {
  int ia[3][4] = { 
    { 0, 1, 2, 3 },
    { 4, 5, 6, 7 },
    { 8, 9, 10, 11 }
  };

  // Method 1
  cout << "Method 1" << endl;
  for(int (&row)[4] : ia) {
    for(int num : row)
      cout << num << ' ';
    cout << endl;
  }

  cout << endl;

  // Method 2
  cout << "Method 2" << endl;
  for(int row = 0; row < sizeof(ia)/sizeof(ia[0]); ++row) {
    for(int col = 0; col < sizeof(ia[0])/sizeof(ia[0][0]); ++col)
      cout << ia[row][col] << ' ';
    cout << endl;
  }

  cout << endl;

  // Method 3
  cout << "Method 3" << endl;
  for(int (*row)[4] = begin(ia); row != end(ia); ++row) {
    for(int *col = begin(*row); col < end(*row); ++col)
      cout << *col << ' ';
    cout << endl;
  }

  return 0;
}
