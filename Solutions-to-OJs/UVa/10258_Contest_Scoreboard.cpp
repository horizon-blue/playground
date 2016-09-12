// Xiaoyan Wang 9/11/2016
// UNTESTED..
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
// #include <array>
#include <algorithm>
using namespace std;

struct Contestant {
	Contestant() = default;
	Contestant(const int &i): id(i), solved(11, false), times(11, 0) { }
	int id;
	int solveno = 0;
	int time = 0;
	bool submitonce = false;
	vector<bool> solved;
	vector<int> times;
	// array<bool, 11> solved(false);
	// array<int, 11> times(0);
};

bool cmprank(const Contestant& c1, const Contestant& c2);

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	string temp;

	getline(cin, temp);
	getline(cin, temp);
	getline(cin, temp);
	// while(getline(cin, temp) && temp.empty());
	while(cases--) {
		vector<Contestant> cont;
		cont.reserve(101);
		for(int i = 0; i < 101; ++i)
			cont.emplace_back(i);

		do {
			istringstream iss(temp);
			int a, b, c;
			char status;
			iss >> a >> b >> c >> status;
			cont[a].submitonce = true;
			if(cont[a].solved[b])
				continue;
			if(status == 'I')
				cont[a].times[b] += 20;
			else if(status == 'C') {
				cont[a].time += cont[a].times[b] + c;
				cont[a].solved[b] = true;
				++(cont[a].solveno);
			}
		} while(getline(cin, temp) && !temp.empty());

		sort(cont.begin(), cont.end(), cmprank);

		for(const Contestant& c : cont) {
			if(!c.submitonce)
				break;
			cout << c.id << ' ' << c.solveno << ' ' << c.time << '\n';
		}
		if(cases)
			cout << '\n';
	}

	cout << flush;
	return 0;
}

bool cmprank(const Contestant& c1, const Contestant& c2) {
	if(c1.submitonce == false)
		return false;
	if(c2.submitonce == false)
		return true;

	if(c1.solveno == c2.solveno) {
		if(c1.time == c2.time)
			return c1.id < c2.id;
		return c1.time < c2.time;
	}
	return c1.solveno > c2.solveno;
}