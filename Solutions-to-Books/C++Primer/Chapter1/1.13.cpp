#include <iostream>

int main() {
	std::cout << "-----Exercise 1.9-----" << std::endl;
	int sum = 0;
	for (int val = 50; val <= 100; ++val)
		sum += val;
	std::cout << "The sum of 50 to 100 inclusive is "
		<< sum << "\n" << std::endl;

	std::cout << "-----Exercise 1.10-----" << std::endl;
	for (int val = 10; val >= 0; --val)
		std::cout << val << std::endl;

	std::cout << "-----Exercise 1.11-----" << std::endl;
	int bound1 = 0, bound2 = 0;
	std::cout << "\n" << "Input two integers:" << std::endl;
	std::cin >> bound1 >> bound2;
	std::cout << "\n" << std::endl;

	if (bound1 > bound2) {
		int temp = bound1;
		bound1 = bound2;
		bound2 = temp;
	}

	for (int i = bound1; i <= bound2; ++i)
		std::cout << i << std::endl;

	return 0;
}