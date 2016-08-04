// Exercise 12.24
// Write a program that reads a string from the standard input into a dynamically allocated
// character array. Describe how your program handles varying size inputs. Test your program
// by giving it a string of data that is longer than the array size you've allocated.
// Xiaoyan Wang 8/4/2016
#include <iostream>
using namespace std;

int main() {
	cout << "How many characters are you about to enter?" << endl;
	size_t sz;
	cin >> sz;
	char *input = new char[sz + 1]();
	cin.ignore();
	cin.getline(input, sz + 1);
	// testing
	// cin.getline(input, sz + 100);
	// The null character is not written at the end, and the excess characters are written
	// beyound the size of the allocated memory. My program does not terminate in this case.
	cout << "The string you enter is: " << input << endl;
	delete [] input;
	return 0;
}