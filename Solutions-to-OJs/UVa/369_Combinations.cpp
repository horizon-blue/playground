// Xiaoyan Wang 11/1/2016
#include <iostream>
using namespace std;

unsigned long long C[101][101];

void init();
// unsigned long long combination(int n, int m);

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	init();
	while(cin >> n >> m && (n || m))
		cout << n << " things taken " << m << " at a time is "
			<<	C[n][m] << " exactly.\n";
	cout << flush;
	return 0;
}

void init() {
	C[0][0] = 1;
	C[1][1] = 1;
	C[1][0] = 1;
	for (int i = 2; i <= 100; ++i) {
		C[i][0] = 1; // base case
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
}

// unsigned long long combination(int n, int m) {
// 	if(stored_values[n][m])
// 		return stored_values[n][m];

// 	// TOO inefficient
// 	// int s = (m > (n - m))? m : (n - m);
// 	// unsigned long long numerator = 1, denominator = 1;
// 	// for(int i = 0; i < s; ++i) {
// 	// 	numerator *= (n-i);
// 	// 	denominator *= (i+1);
// 	// 	cout << numerator << endl;
// 	// 	for(int j = denominator; j > 1; --j)
// 	// 		if(!(denominator%j) && !(numerator%j)) {
// 	// 			numerator/=j;
// 	// 			denominator/=j;
// 	// 		}
// 	// }
// 	// stored_values[n][m] = numerator;
// 	// return numerator;
// }