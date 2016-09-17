// Xiaoyan Wang 9/17/2016
#include <iostream>
#include <vector>
using namespace std;

void mark_friends(int f, vector<vector<int>>& frivec, vector<bool>& visited);

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	while(cases--) {
		int N, e;
		cin >> N >> e;
		if(!e) {// no one is friends with any one
			cout << N << '\n';
			continue;
		}
		vector<vector<int>> frivec(N, vector<int>());
		for(int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			frivec[a].push_back(b);
			frivec[b].push_back(a);
		}

		int groupcount = 0;
		vector<bool> visited(N, false);
		for(int f = 0; f < N; ++f) {
			if(!visited[f]) {
				mark_friends(f, frivec, visited);
				++groupcount;
			}
		}
		cout << groupcount << '\n';
	}
	cout << flush;
	return 0;
}

void mark_friends(int f, vector<vector<int>>& frivec, vector<bool>& visited) {
	if(visited[f])
		return;

	visited[f] = true;
	
	for(int fri : frivec[f])
		mark_friends(fri, frivec, visited);
}