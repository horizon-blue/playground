// Xiaoyan Wang 10/6/2015
#include <iostream>
using namespace std;

void printStarRow(int col) {
	for (int c = 0; c < col * 3 + 1; ++c)
		cout << "*";
	cout << endl;
}

void printStarDotRow(int col) {
	for (int i = 0; i < col; ++i) {
		cout << "*";
		cout << "..";
	}
	cout << "*" << endl;
}

void printEntireGraph(int row, int col) {
	printStarRow(col);
	for (int r = 0; r < row; ++r) {
		printStarDotRow(col);
		printStarDotRow(col);
		printStarRow(col);
	}
}

int main() {
	int times;
	cin >> times;
	while (times) {
		--times;
		int row, col;
		cin >> row >> col;
		printEntireGraph(row, col);
		cout << endl;
	}
	return 0;
}