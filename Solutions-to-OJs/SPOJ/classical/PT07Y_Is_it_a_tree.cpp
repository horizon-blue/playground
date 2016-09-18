// Xiaoyan Wang 9/18/2016
#include <iostream>
#include <vector>
using namespace std;

bool mark_tree(const int& node, const int& prev, const vector<vector<int> >& map, vector<bool>& visited);

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > map(N+1, vector<int>());
	vector<bool> visited(N+1, false);
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	bool success = mark_tree(1, 0, map, visited);

	if(success) {
		for(int i = 1; i <= N; ++i) {
			if(!visited[i]) {
				success = false;
				break;
			}
		}
	}

	if(success)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;

}

bool mark_tree(const int& node, const int& prev, const vector<vector<int> >& map, vector<bool>& visited) {
	if(visited[node])
		return false;

	visited[node] = true;

	for(const int& n : map[node]) {
		if(n == prev)
			continue;
		bool success = mark_tree(n, node, map, visited);
		if(!success)
			return false;
	}
	return true;
}