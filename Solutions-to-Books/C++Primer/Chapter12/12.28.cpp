// Exercise 12.28
// Write a program to implement text queries without defining classes to manage the data.
// Your program should take a file and interact with a user to query for words in that file.
// Use vector, map, and set containers to hold the data for the file and
// to generate the results for the queries.
// A combination of 12.27.h, 12.27.cpp and 12.27_main.cpp
// Xiaoyan Wang 8/4/2016
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
	ifstream infile("12.27.txt");
	vector<string> text;
	map<string, set<size_t>> wordcount;

	size_t currline = 0;
	for(string line; getline(infile, line); ++currline) {
		text.push_back(line);
		istringstream iss(line);
		string word;
		while(iss >> word)
			wordcount[word].insert(currline);
	}

	while (true) {
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q")
			break;
		
		auto loc = wordcount.find(s);
		if (loc == wordcount.end())
			cout << s << " doesn't appear in the text." << endl;
		else {
			cout << s << " occurs "	<< (loc -> second).size()
			<< ((loc -> second).size() > 1 ? " times" : " time") << endl;

			for(const auto& currline : loc -> second)
				cout << "\t(line " << currline << ") " << text[currline] << endl;
		}
		cout << endl;
	}
	return 0;
}