// Google Code Jam 2017 Qualification Run
// Xiaoyan Wang 04/07/2017
// This implementation is incorrect and did not pass the grader
#include <iostream>
#include <cmath>
using namespace std;

int remains(int stall, int ppl);

int main() {
	int cases;
	cin >> cases;
	for(int run = 1; run <= cases; ++run) {
		int stall, ppl;
		cin >> stall >> ppl;
		int rem = remains(stall, ppl);
		cout << "Case #" << run << ": " << rem - rem / 2 << ' ' << rem / 2 << '\n';
	}
	cout << flush;

	return 0;
}

int remains(int stall, int ppl) {
	// int temp = floor(log2(ppl));
	// temp = 1 << temp;
	return ceil((stall+1.0)/ppl-1) - 1;
}