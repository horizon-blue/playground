// Xiaoyan Wang 9/10/2016
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int X;
	cin >> X;
	for(int x = 1; x <= X; ++x) {
		vector<int> count(26, 0);
		int R, C, M, N;
		cin >> R >> C >> M >> N;

		for(int i = R * C; i > 0; --i) {
			char c;
			cin >> c;
			++count[c - 'A'];
		}

		int imp_count = 0, max_freq = 0;
		for(const int& freq : count)
			if(freq > max_freq)
				imp_count = max_freq = freq;
			else if(freq == max_freq)
				imp_count += freq;

		cout << "Case " << x << ": " << imp_count * M + (R * C - imp_count) * N << "\n";
	}

	cout << flush;

	return 0;
}