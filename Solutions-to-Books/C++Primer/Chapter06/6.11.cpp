// Xiaoyan Wang 12/28/2015
#include <iostream>
using namespace std;

void reset(int &num) {
	num = 0;
}

int main() {
	cout << "Enter an integer: ";
	int num;
	cin >> num;
	reset(num);
	cout << "The integer is reset to " << num << endl;

	return 0;
}