// Xiaoyan Wang 12/27/2015
#include <iostream>
using namespace std;

int abs(int ori) {
	if (ori >= 0)
		return ori;
	else
		return -ori;
}

int main() {
	int num;
	cin >> num;
	cout << abs(num) << endl;

	return 0;
}