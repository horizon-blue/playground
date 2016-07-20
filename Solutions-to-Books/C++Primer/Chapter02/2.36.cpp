#include <iostream>

int main() {
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	std::cout << a << " " << b << " " << c
		<< " " << d << std::endl;
	++c;
	++d;
	std::cout << a << " " << b << " " << c
		<< " " << d << std::endl;

	return 0;
}