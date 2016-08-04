// Exercise 12.30
// Define your own versions of the TextQuery and QueryResult classes and
// execute the runQueries function from Section 12.3.1
// Xiaoyan Wang 8/5/2016
#include <fstream>
#include <string>
#include <iostream>
#include "12.30.h"
using namespace std;

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main() {
	ifstream infile("12.27.txt");
	runQueries(infile);
	infile.close();

	return 0;
}