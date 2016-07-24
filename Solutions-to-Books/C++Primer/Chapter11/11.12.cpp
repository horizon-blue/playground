// Exercise 11.12
// Write a program to read a sequence of strings and ints, storing each
// into a pair. Store the pairs in a vector
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
	vector<pair<string, int>> pvec;
	string s;
	int i;
	cout << "Please enter some string and int pairs:" << endl;
	while(cin >> s >> i)
		pvec.push_back({s, i});
	cout << "The pairs in pvec are:" << endl;
	for(const auto& p : pvec)
		cout << p.first << ", " << p.second << endl;

	return 0;
}