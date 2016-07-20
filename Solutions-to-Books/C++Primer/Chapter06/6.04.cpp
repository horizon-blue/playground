// Xiaoyan Wang 12/27/2015
#include <iostream>
using std::cin; using std::cout; using std::endl;

int fact(int n) {
	int result = 1;
	while (n) {
		result *= n;
		--n;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	cout << n << "! equals " << fact(n) << "." << endl;

	return 0;
}