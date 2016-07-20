// Xiaoyan Wang 12/28/2015
#include <iostream>
using namespace std;

int callCount() {
	static int count = 0;
	return ++count;
}

int main() {
	int times;
	cout << "Enter the number of times you want to call the function: ";
	cin >> times;
	for (; times; --times)
		cout << "This is the " << callCount()
		<< " time the function is called." << endl;

	return 0;
}