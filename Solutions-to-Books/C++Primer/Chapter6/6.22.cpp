// Xiaoyan Wang 12/30/2015
#include <iostream>
using namespace std;

void ptrSwap(int *a, int *b) {
	int *temp = a;
	a = b;
	b = temp;
}

int main() {
	int a, b;
	cin >> a >> b;
	int *c, *d;
	c = &a;
	d = &b;
	swap(c, d);
	cout << *c << ' ' << *d;

	return 0;
}