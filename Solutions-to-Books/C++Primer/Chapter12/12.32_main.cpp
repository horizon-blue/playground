// Exercise 12.32
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of
// a vector<string> to hold the input file
// Xiaoyan Wang 8/5/2016
#include <fstream>
#include <string>
#include <iostream>
#include "12.32.h"
#include "strblob.h" // for StrBlob
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