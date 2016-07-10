#include <iostream>

int main() {
	int a = 10, b = 20;
	int *aptr = nullptr, *bptr = 0;
	if (aptr == bptr)
		std::cout << "aptr is equal to bptr" << std::endl;

	aptr = &a, bptr = &b;
	std::cout << *aptr << " " << *bptr << std::endl;
	
	*bptr = 10;
	std::cout << *aptr << " " << *bptr << std::endl;
	if (*aptr == *bptr)
		std::cout << "the value of aptr is equal to the value of bptr" << std::endl;

	return 0;
}