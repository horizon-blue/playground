// Xiaoyan Wang 9/29/2016
#include <iostream>
// #include <unordered_map>
#include <string>
// #include <sstream>
#include <initializer_list>
#include <vector>
using namespace std;

int indexof(const char& c);
int find_best();
vector<vector<int>> cities;
vector<vector<int>> rules;


int main() {
	string line;
	rules = vector<vector<int>>(5, vector<int>(5, 0));

	while(getline(cin, line)) {
		if(line[0] == 'e') {
			int result = find_best();
			cout << result << '\n';
			getline(cin, line);
			if(line == "#")
				break;
			cities.clear();
			for(auto& r : rules)
				for(auto& i : r)
					i = 0;
		}

		cities.emplace_back(initializer_list<int>{indexof(line[0]), indexof(line[2]), indexof(line[4]),
				indexof(line[6]), indexof(line[8]), indexof(line[10]), indexof(line[12]),
				indexof(line[14]), indexof(line[16]), indexof(line[18])});

		for(int i = 0; i < 10; i += 2) {
			int waste = cities.back()[i + 1];
			for(int j = 0; j < 5; ++j)
				if(j != waste)
					++rules[cities.back()[i]][j];
		}
	}

	cout << flush;
	return 0;
}

int indexof(const char& c) {
	switch(c) {
		case 'r':
		case 'P':
			return 0;
		case 'o':
		case 'G':
			return 1;
		case 'y':
		case 'A':
			return 2;
		case 'g':
		case 'S':
			return 3;
		case 'b':
		case 'N':
			return 4;
		default:
			return -1;
	}
}

int find_best() {
	int best_city = 0;
	int least_move = 5000;
	for(int i = 0; i < cities.size(); ++i) {
		int totalchange = 0;
		const auto& city = cities[i]; // give a alias for quiker reference
		for(int a = 0; a < city.size(); a += 2)
			totalchange += rules[city[a]][city[a + 1]];
		if(totalchange < least_move) {
			least_move = totalchange;
			best_city = i;
		}
	}

	return best_city + 1;
}