#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item book1, book2;
	std::cout << "Enter two books with same ISBN:" << std::endl;
	std::cin >> book1 >> book2;
	std::cout << book1 + book2 << std::endl;

	return 0;
}