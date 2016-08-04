// Exercise 12.32
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of
// a vector<string> to hold the input file
// Xiaoyan Wang 8/5/2016
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include "12.32.h"
#include "strblob.h" // for StrBlob
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(ifstream &is) {
	string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<StrBlob::size_type>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<StrBlob::size_type>> nodata(new set<StrBlob::size_type>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
	<< make_plural(qr.lines->size(), "times", "s") << endl;

	for(auto num : *qr.lines) {
		ConstStrBlobPtr temp(qr.file, num);
		os << "\t(line " << num + 1 << ") " << temp.deref() << endl;
	}
	return os;
}