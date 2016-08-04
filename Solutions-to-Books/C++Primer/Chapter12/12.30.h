// Exercise 12.30
// Define your own versions of the TextQuery and QueryResult classes and
// execute the runQueries function from Section 12.3.1
// Xiaoyan Wang 8/5/2016
#ifndef EX_12_30_H
#define EX_12_30_H
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>

class QueryResult;
std::string make_plural(std::size_t, const std::string&, const std::string&);

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
		std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

#endif