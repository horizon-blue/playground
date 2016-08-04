// Exercise 12.27
// The TextQuery and QueryResult classes use only capabilities that we have already covered. 
// Without looking ahead, write your own versions of these classes.
// Xiaoyan Wang 8/4/2016
#include <fstream>
#include <string>
#include <iostream>
#include "12.27.h"
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