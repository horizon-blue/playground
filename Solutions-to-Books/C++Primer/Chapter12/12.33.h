// Exercise 12.33
// In Chapter 15 we’ll extend our query system and will need some additional members
// in the QueryResult class. Add members named begin and end that return iterators into
// the set of line number returned by a given query, and a member named get_file that
// returns a shared_ptr to the file in the QueryResult object.
// Xiaoyan Wang 8/5/2016
#ifndef EX_12_33_H
#define EX_12_33_H
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
	std::set<TextQuery::line_no>::iterator begin() const { return lines -> begin(); }
	std::set<TextQuery::line_no>::iterator end() const { return lines -> end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }

private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

#endif