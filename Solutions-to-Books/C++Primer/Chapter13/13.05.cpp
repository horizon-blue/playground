// Exercise 13.05
// Given the following sketch of a class, write a copy constructor that copies all the
// members. Your constructor should dynamically alocate a new string and copy the object
// to which ps points, rather than copying ps itself.
// Xiaoyan Wang 8/7/2016
#include <string>
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &rhs): ps(new std::string(*rhs.ps)), i(rhs.i) { }
	~HasPtr() {
		delete ps;
	}

private:
	std::string *ps;
	int i;
};

// testing
int main() {
	HasPtr hp1("Testing");
	HasPtr hp2 = hp1;
	return 0;
}