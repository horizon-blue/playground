#include <iostream>
#include <string>
#include "Sales_data.h"

int main() {
	Sales_data data1, data2;
	double price;
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = price * data1.units_sold;
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = price * data2.units_sold;

	if (data1.bookNo == data2.bookNo) {
		unsigned totalSold = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		std::cout << data1.bookNo << " " << totalSold
			<< " " << totalRevenue << " ";
		if (totalSold != 0)
			std::cout << totalRevenue / totalSold << std::endl;
		else
			std::cout << "(no sales)" << std::endl;

		return 0;
	}
	else {
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}