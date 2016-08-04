// Another name for 12.22.cpp - header part
#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>
using std::vector;
using std::string;

class StrBlobPtr;
class ConstStrBlobPtr;

// class StrBlob is mostly copied from 12.02.cpp
class StrBlob {
	friend StrBlobPtr;
	friend ConstStrBlobPtr;
public:
	typedef vector<string>::size_type size_type;

	// constructors
	StrBlob(): data(std::make_shared<vector<string>>()) { }
	StrBlob(std::initializer_list<string> il): data(std::make_shared<vector<string>>(il)) { }

	size_type size() const { return data -> size(); }
	bool empty() const { return data -> empty(); }
	
	StrBlobPtr begin();
	StrBlobPtr end();
	// NEW: const begin and end operations
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
	
	// add and remove elements
	void push_back(const string &t) { data -> push_back(t); }
	void pop_back();

	// element access
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	std::shared_ptr<vector<string>> data;
	// throw msg if data[i] isn't valid
	void check(size_type i, const string &msg) const {
		if (i >= data -> size())
			throw std::out_of_range(msg);
	}
};

class StrBlobPtr {
public:
	// constructors
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &sb, std::size_t sz = 0): dataptr(sb.data), curr(sz) { }

	string& deref() const;
	StrBlobPtr& incr();

	friend bool isequal(const StrBlobPtr &sbptr1, const StrBlobPtr &sbptr2);

private:
	// helper function
	std::shared_ptr<vector<string>> check(std::size_t pos, const string &msg) const;
	// data
	std::weak_ptr<vector<string>> dataptr;
	std::size_t curr;
};

class ConstStrBlobPtr {
public:
	// constructors
	ConstStrBlobPtr(): curr(0) { }
	// the first parameter should be of the type const StrBlob &
	ConstStrBlobPtr(const StrBlob &sb, std::size_t sz = 0): dataptr(sb.data), curr(sz) { }

	string& deref() const;
	ConstStrBlobPtr& incr();

	friend bool isequal(const ConstStrBlobPtr &sbptr1, const ConstStrBlobPtr &sbptr2);

private:
	// helper function
	std::shared_ptr<vector<string>> check(std::size_t pos, const string &msg) const;
	// data
	std::weak_ptr<vector<string>> dataptr;
	std::size_t curr;
};

#endif