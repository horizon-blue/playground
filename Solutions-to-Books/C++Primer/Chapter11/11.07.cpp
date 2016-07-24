// Exercise 11.7
// Define a map for which the key is the family's last name and the value
//  is a vector of the children's names. Write code to add new families and to add new children
// to an existing family
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	map<string, vector<string>> families;
	cout << "Enter names of the children:" << endl;
	string first, last;
	while(cin >> first >> last)
		families[last].push_back(first);

	cout << "The families are:\n";
	for (const auto& f : families) {
		cout << f.first << "'s:";
		for(const auto& name : f.second)
			cout << ' ' << name;
		cout << endl;
	}
	return 0;	
}