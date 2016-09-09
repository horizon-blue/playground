// Xiaoyan Wang 10/1/2015
#include <iostream>

int main() {
	int counts = 0;
	std::cin >> counts;
	int row[100], col[100];
	for (int i = 0; i < counts; ++i)
		std::cin >> row[i] >> col[i];
	for (int i = 0; i < counts; ++i) {
		for (int r = 0; r < row[i]; ++r) {
			for (int c = 0; c < col[i]; ++c) {
				if (r == 0 || r == row[i] - 1)
					std::cout << "*";
				else {
					if (c == 0 || c == col[i] - 1)
						std::cout << "*";
					else
						std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}