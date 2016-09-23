// Xiaoyan Wang 9/23/2016
#include <iostream>
// #include <unordered_set>
using namespace std;

// struct coord {
// 	int x;
// 	int y;
// 	coord() = default;
// 	coord(const int& _x, const int& _y): x(_x), y(_y) { }
// };

char grid[20][20];
bool visited[20][20];
int check_entrance(const int& m, const int& n);
bool isvalid(const int& m, const int& n, const int& x, const int& y);
int sx, sy, ex, ey;

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	while(cases--) {
		int m, n;
		cin >> m >> n;
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j) 
				cin >> grid[i][j];

		if(m == 1 && n == 1) {
			cout << "invalid\n";
			continue;
		}

		if(check_entrance(m, n) != 2) {
			cout << "invalid\n";
			continue;
		}

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				visited[i][j] = false;

		if(isvalid(m, n, sx, sy))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	cout << flush;
	return 0;
}

int check_entrance(const int& m, const int& n) {
	int result = 0;
	for(int i = 0; i < n; ++i) // check the first row
		if(grid[0][i] == '.') {
			if(!result) {
				sy = 0;
				sx = i;
			}
			else if(result == 1) {
				ey = 0;
				ex = i;
			}
			++result;
		}
	if(m != 1)
		for(int i = 0; i < n; ++i)
			if(grid[m-1][i] == '.') {
				if(!result) {
					sy = m - 1;
					sx = i;
				}
				else if(result == 1) {
					ey = m - 1;
					ex = i;
				}
				++result;
			}
	for(int j = 1; j < m - 1; ++j)
		if(grid[j][0] == '.') {
			if(!result) {
				sy = j;
				sx = 0;
			}
			else if(result == 1) {
				ey = j;
				ex = 0;
			}
			++result;
		}

	if(n != 1)
		for(int j = 1; j < m - 1; ++j) 
			if(grid[j][n-1] == '.') {
				if(!result) {
					sy = j;
					sx = n - 1;
				}
				else if(result == 1) {
					ey = j;
					ex = n - 1;
				}
				++result;
			}

	return result;
}


bool isvalid(const int& m, const int& n, const int& x, const int& y) {
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if(x == ex && y == ey)
		return true;

	if(grid[y][x] == '#' || visited[y][x])
		return false;

	visited[y][x] = true;
	return isvalid(m, n, x - 1, y) || isvalid(m, n, x + 1, y) ||
			isvalid(m, n, x, y - 1) || isvalid(m, n, x, y + 1);
}