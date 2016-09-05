// Xiaoyan Wang 9/3/2016
#include <iostream>
using namespace std;

int main() {
	double sum = 0;
	double curr = 0;
	for(int i = 0; i < 12; ++i) {
		cin >> curr;
		sum += curr;
	}
	cout.precision(2);
	cout << '$' << fixed << sum / 12 << endl;
	return 0;
}