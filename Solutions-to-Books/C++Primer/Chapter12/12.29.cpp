// Exercise 12.29
// We could have written the loop to manage the interaction with the user
// as a do while loop. Rewrite the loop to use a do while. Explain which
// version you prefer and why.
// Xiaoyan Wang 8/5/2016

// Mostly copied from 12.27_main.cpp

#include <fstream>
#include <string>
#include <iostream>
#include "12.27.h"
using namespace std;

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	cout << "Enter word to look for: ";
	string s;
	cin >> s;
	do {
		print(cout, tq.query(s)) << endl;
		cout << "Enter another word to look for, or q to quit: ";
	} while (cin >> s && s != "q");
}

int main() {
	ifstream infile("12.27.txt");
	runQueries(infile);
	infile.close();

	return 0;
}