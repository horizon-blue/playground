// Exercise 6.38 - Revise the arrPtr function on to
// return a reference to the array
#include <iostream>
using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrRef(int i) {
  return (i % 2) ? odd : even;
}

int main() {
  cout << "Enter a number: " << endl;
  int num;
  cin >> num;

  int index = 0;
  do {
    cout << "Enter an index for the number, "
	 << "from 0 to 4." << endl;
    cin >> index;
  } while(index < 0 || index > 4);

  arrRef(num)[index] = num;

  cout << "The new array is:";
  for(int i = 0; i < 5; ++i)
    cout << ' ' << arrRef(num)[i];

  cout << endl;

  return 0;
}  
