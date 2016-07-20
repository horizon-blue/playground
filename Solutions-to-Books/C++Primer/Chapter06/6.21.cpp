// Xiaoyan Wang 12/30/2015
#include <iostream>
using namespace std;

int larger(const int ival, const int *iptr) {
	return (ival > *iptr) ? ival : *iptr;
}

int main() {
	int ival1, ival2;
	cin >> ival1 >> ival2;
	cout << larger(ival1, &ival2) << endl;

	return 0;
}