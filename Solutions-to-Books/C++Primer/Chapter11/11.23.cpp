// Exercise 11.23
// Rewrite the map that stored vectors of children’s names with a key that is the family last name for
// the exercises in Section 11.2.1 to use a multimap.
// Mostly copied from 11.14.cpp
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	multimap<string, pair<string, string>> families;
	cout << "Enter names and birthday of the children:" << endl;
	string first, last, birth;
	while(cin >> first >> last >> birth)
		families.emplace(last, make_pair(first, birth));

	cout << "The families are:\n";
	for (const auto& f : families)
		cout << f.first << "'s: " << f.second.first <<  " - " << f.second.second << endl;
	return 0;	
}