#include <iostream>

int main() {
	int bound1 = 0, bound2 = 0;
	std::cout << "Input two integers:" << std::endl;
	std::cin >> bound1 >> bound2;
	
	if (bound1 > bound2) {
		int temp = bound1;
		bound1 = bound2;
		bound2 = temp;
	}

	while (bound1 <= bound2) {
		std::cout << bound1 << std::endl;
		++bound1;
	}

	return 0;
}