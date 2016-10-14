// Xiaoyan Wang 10/14/2016
// Using Floyd-Warshall Algorithm
#include <iostream>
#include <vector>
#include <utility> // for std::move
#include <algorithm> // for std::min
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int test_cases = 0;
	int a, b;
	vector<vector<int> > cmap;
	while(cin >> a) {
		++test_cases;
		cmap = move(vector<vector<int> >(21, vector<int>(21, 100)));
		for(int i = 0; i < a; ++i) {
			cin >> b;
			cmap[1][b] = 1;
			cmap[b][1] = 1;
		}
		// finish rest of table
		for(int i = 2; i < 20; ++i) {
			cin >> a;
			for(int j = 0; j < a; ++j) {
				cin >> b;
				cmap[i][b] = 1;
				cmap[b][i] = 1;
			}
		}

		// do the computation
		for(int k = 1; k < 21; ++k)
			for(int i = 1; i < 21; ++i)
				for(int j = 1; j < 21; ++j)
					cmap[i][j] = min(cmap[i][j], cmap[i][k] + cmap[k][j]);

		int num_quest; // number of conquests
		cin >> num_quest;
		cout << "Test Set #" << test_cases << '\n';
		while(num_quest--) {
			cin >> a >> b;
			cout.width(2);
			cout << a << " to ";
			cout.width(2);
			cout << b;
			cout << ": " << cmap[a][b] << '\n';
		}
		cout << '\n';
	}
	cout << flush;
	return 0;
}