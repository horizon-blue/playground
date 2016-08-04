// Exercise 12.32
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of
// a vector<string> to hold the input file
// Xiaoyan Wang 8/5/2016
#ifndef EX_12_32_H
#define EX_12_32_H
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>
#include "strblob.h" // for StrBlob

class QueryResult;
std::string make_plural(std::size_t, const std::string&, const std::string&);

class TextQuery {
public:
	// using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wm;
};

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<StrBlob::size_type>> p,
		const StrBlob &f): sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<StrBlob::size_type>> lines;
	StrBlob file;
};

#endif