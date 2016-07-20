// Xiaoyan Wang 12/28/2015
#include <iostream>
using namespace std;

void ptrSwap(int *ip1, int *ip2) {
	int temp = *ip1;
	*ip1 = *ip2;
	*ip2 = temp;
}

int main() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	ptrSwap(&a, &b);
	cout << "After swapping, a = " << a
		<< ", b = " << b << "." << endl;

	return 0;
}