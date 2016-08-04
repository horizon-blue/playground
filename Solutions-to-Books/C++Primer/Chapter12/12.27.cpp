// Exercise 12.27
// The TextQuery and QueryResult classes use only capabilities that we have already covered. 
// Without looking ahead, write your own versions of these classes.
// Xiaoyan Wang 8/4/2016
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include "12.27.h"
using namespace std;

TextQuery::TextQuery(ifstream &infile): text(make_shared<vector<string>>()) {
	size_t currline = 0;
	for(string line; getline(infile, line); ++currline) {
		text -> push_back(line);
		istringstream iss(line);
		string word;
		while(iss >> word) {
			auto &lineset = wordcount[word];
			if(!lineset)// if the word is added for the first time
				lineset = make_shared<set<size_t>>();
			lineset -> insert(currline);
		}
	}
}

QueryResult TextQuery::query(const string &s) const {
	auto loc = wordcount.find(s);
	if (loc != wordcount.end())
		return QueryResult(s, text, loc -> second);
	else
		return QueryResult(s, text, shared_ptr<set<size_t>>());
}

ostream& print(ostream &os, const QueryResult &qr) {
	if (!qr.line_num)
		os << qr.word << " doesn't appear in the text." << endl;
	else {
		os << qr.word << " occurs "	<< qr.line_num ->size()
		<< (qr.line_num -> size() > 1 ? " times" : " time") << endl;

		for(const auto& currline : *qr.line_num)
			os << "\t(line " << currline << ") " << (*(qr.text))[currline] << endl;
	}
	return os;
}