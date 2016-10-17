#include <iostream>
#include <algorithm> // for std::sort
#include <unordered_set>
#include <vector>
using namespace std;

struct Edge {
	Edge() = default;
	Edge(int a, int b, int c): u(a), v(b), length(c) { }
	int u;
	int v;
	int length;
};

bool operator <(const Edge& e1, const Edge &e2) {
	return e1.length < e2.length;
}

int root(int a, vector<int>& parents);

int main() {
	ios::sync_with_stdio(false);
	int m, n;
	while(cin >> m >> n && m && n) {
		if(!n) {
			cout << 0 << '\n';
			continue;
		}
		vector<Edge> roads;
		roads.reserve(n);
		int a, b, c;
		int currentlength = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			roads.emplace_back(a, b, c);
			currentlength += c;
		}
		sort(roads.begin(), roads.end());

		vector<int> parents;
		parents.reserve(m);
		for(int i = 0; i < m; ++i)
			parents.push_back(i);
		vector<int> groupsize(m, 1);
		unordered_set<int> visited;
		visited.reserve(m);
		int totallength = 0;
		auto loc = roads.begin();
		int parentu, parentv;
		while(visited.size() <= m && loc != roads.end()) {
			parentu = root(loc -> u, parents);
			parentv = root(loc -> v, parents);
			if(parentu == parentv) { // this will create a circle
				++loc;
				continue;
			}
			if(groupsize[parentu] > groupsize[parentv])
				swap(parentu, parentv);
			parents[parentu] = parentv;
			groupsize[parentv] += groupsize[parentu];
			totallength += loc -> length;
			visited.insert(loc -> u);
			visited.insert(loc -> v);
			++loc;
		}
		cout << currentlength - totallength << '\n';
	}
	cout << flush;
	return 0;
}

int root(int a, vector<int>& parents) {
	if(parents[a] == a)
		return a;
	int temp = a;
	while(parents[temp] != temp)
		temp = parents[temp];
	parents[a] = temp;
	return temp;
}