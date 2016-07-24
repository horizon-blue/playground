// Exercise 11.14
// Extend the map of children to their family name that you wrote for the
// exercises in Section 11.2.1 by having the vector store a pair that
// holds a child’s name and birthday.
// Mostly copied from 11.7.cpp
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	map<string, vector<pair<string, string>>> families;
	cout << "Enter names and birthday of the children:" << endl;
	string first, last, birth;
	while(cin >> first >> last >> birth)
		families[last].emplace_back(first, birth);

	cout << "The families are:\n";
	for (const auto& f : families) {
		cout << f.first << "'s:";
		for(const auto& child : f.second)
			cout << ' ' << child.first <<  " - " << child.second << ';';
		cout << endl;
	}
	return 0;	
}