// Exercise 12.27
// The TextQuery and QueryResult classes use only capabilities that we have already covered. 
// Without looking ahead, write your own versions of these classes.
// Xiaoyan Wang 8/4/2016
#ifndef EX_12_27_H
#define EX_12_27_H
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <set>

class TextQuery;
class QueryResult;

class TextQuery {
public:
	// TextQuery() = default;
	TextQuery(std::ifstream &infile);
	QueryResult query(const std::string &s) const;
	
private:
	std::shared_ptr<std::vector<std::string>> text;
	std::map<std::string, std::shared_ptr<std::set<std::size_t>>> wordcount;
};

class QueryResult {
	friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:
	// QueryResult() = default;
	QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> t,
		std::shared_ptr<std::set<std::size_t>> lm): word(s), text(t), line_num(lm) { }
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> text;
	std::shared_ptr<std::set<std::size_t>> line_num;
};

#endif