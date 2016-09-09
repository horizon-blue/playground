// Xiaoyan Wang 10/13/2015
#include <iostream>
using namespace std;

void printStarRow(int col, int subcol) {
	cout << "*";
	for (int i = 0; i < col; ++i)
		for (int sc = 0; sc < subcol + 1; ++sc)
			cout << "*";
	cout << endl;
}

void printCombineRow(int col, int subcol) {
	cout << "*";
	for (int i = 0; i < col; ++i) {
		for (int sc = 0; sc < subcol; ++sc)
			cout << ".";
		cout << "*";
	}
	cout << endl;
}

int main() {
	int rounds;
	cin >> rounds;

	for (int i = 0; i < rounds; ++i) {
		int row, col, subrow, subcol;
		cin >> row >> col >> subrow >> subcol;

		printStarRow(col, subcol);
		for (int r = 0; r < row; ++r) {
			for (int sr = 0; sr < subrow; ++sr)
				printCombineRow(col, subcol);
			printStarRow(col, subcol);
		}
		cout << endl;
	}
	return 0;
}