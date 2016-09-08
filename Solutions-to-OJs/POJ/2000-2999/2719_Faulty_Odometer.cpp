// Xiaoyan Wang 9/8/2016
#include <iostream>
// #include <vector>
using namespace std;

// arry stores 0, 9^1, 9^2 ... 9^8
int arry[] = {1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721/*, 387420489*/};

// input range: 1 to 10^10
int main() {
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n && n) {
		int result = 0;
		int digit;
		for(int i = 0, div = 1; i < 10; ++i, div *= 10) {
			if((digit = (n % (div * 10)) / div) > 4)
				--digit;
			result += digit * arry[i];
		}
		cout << n << ": " << result << "\n";
	}
	cout << flush;
	return 0;
}