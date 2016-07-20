// Xiaoyan Wang 12/28/2015
#include <iostream>
using namespace std;

void ptrSwap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	ptrSwap(a, b);
	cout << "After swapping, a = " << a
		<< ", b = " << b << "." << endl;

	return 0;
}