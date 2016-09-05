// Xiaoyan Wang 9/4/2016
#include <iostream>
#include <vector>
using namespace std;

int main() {
	for(int set = 1, box; cin >> box && box; ++set) {
		int mean = 0;
		vector<int> brisk;
		brisk.reserve(box);
		for(int i = 0, temp; i < box; ++i) {
			cin >> temp;
			mean += temp;
			brisk.push_back(temp);
		}
		mean /= box;
		int result = 0;
		for(int i = 0; i < box; ++i) {
			if(brisk[i] > mean)
				result += brisk[i] - mean;
		}
		ios::sync_with_stdio(false);
		cout << "Set #" << set << '\n';
		cout << "The minimum number of moves is " << result << ".\n\n";
	}
	cout << flush;
	return 0;
}