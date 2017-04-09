// Google Code Jam 2017 Qualification Run
// Xiaoyan Wang 04/07/2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int l = 1; l <= cases; ++l) {
		string pancakes;
		int k;
		cin >> pancakes >> k;
		int count = 0;
		for(int i = 0; i < pancakes.size() - k + 1; ++i) {
			if(pancakes[i] == '-') {
				// flipped the pancakes
				++count;
				for (int j = 0; j < k; ++j) {
					if(pancakes[i+j] == '-')
						pancakes[i + j] = '+';
					else
                        pancakes[i + j] = '-';
                }
			}
		}
		for(int i = pancakes.size() - k + 1; i < pancakes.size(); ++i)
			if(pancakes[i] == '-') {
				cout << "Case #" << l << ": IMPOSSIBLE\n";
				count = -1;
				break;
			}
		if(count >= 0)
			cout << "Case #" << l << ": " << count << '\n';

	}
	cout << flush;
	return 0;
}