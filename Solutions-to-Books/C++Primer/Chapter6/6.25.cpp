// Xiaoyan Wang 12/31/2015
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string result;
	for (int i = 1; i < argc; ++i)
		result += argv[i] + ' ';

	cout << result << endl;

	return 0;
}
