// Exercise 11.32
// Using the multimap from the previous exercise, write a program to print
// the list of authors and their works alphabetically
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	// Copied from 11.31.cpp
	multimap<string, string> books;
	cout << "Enter the name of the authors and their books:" << endl;
	for (string auth, work; cin >> auth >> work; books.emplace(auth, work));
	cin.clear();
	// end of copy range

	map<string, vector<string>> newmap;
	for(const auto& p : books)
		newmap[p.first].push_back(p.second);

	cout << "The authors and their books are:" << endl;
	for(const auto& author : newmap) {
		cout << author.first << ':';
		for(const auto& b : author.second)
			cout << ' ' << b;
		cout << endl;
	}
	return 0;
}