// Exercise 12.2
// Write your own version of the StrBlob class including the const versions of front anc Back.
// Xiaoyan Wang 7/27/2016
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>
using std::vector;
using std::string;

class StrBlob {
public:
	typedef vector<string>::size_type size_type;

	// constructors
	StrBlob(): data(std::make_shared<vector<string>>()) { }
	StrBlob(std::initializer_list<string> il): data(std::make_shared<vector<string>>(il)) { }

	size_type size() const { return data -> size(); }
	bool empty() const { return data -> empty(); }
	
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

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data -> pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data -> front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data -> back();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data -> front();
}

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data -> back();
}