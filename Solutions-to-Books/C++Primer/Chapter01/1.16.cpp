#include <iostream>

int main() {
	int sum = 0, val = 0;
	std::cout << "Input a list of numbers:" << std::endl;
	while (std::cin >> val)
		sum += val;
	std::cout << "The sum of all numbers = " << sum << std::endl;

	return 0;
}