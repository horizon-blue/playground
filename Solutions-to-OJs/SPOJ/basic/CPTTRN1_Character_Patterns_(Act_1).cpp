// Xiaoyan Wang 9/26/2015
#include <iostream>

int main() {
	int num;
	std::cin >> num;
	int row[100], col[100];
	for (int i = 0; i < num; ++i)
		std::cin >> row[i] >> col[i];
	for (int i = 0; i < num; ++i) {
		for (int r = 0; r < row[i]; ++r) {
			for (int c = 0; c < col[i]; ++c) {
				if ((r + c) % 2)
					std::cout << ".";
				else
					std::cout << "*";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}