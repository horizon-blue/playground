// Exercise 11.33
// Implement your own version of the word-transfromation program.
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using std::runtime_error;
using std::cout;
using std::map;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::endl;

void word_transform(ifstream &map_file, ifstream &input);
map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const map<string, string> &m);

int main() {
	ifstream map_file("rules"), input("text");
	word_transform(map_file, input);
	return 0;
}

void word_transform(ifstream &map_file, ifstream &input) {
	map<string, string> trans_map = buildMap(map_file);
	string text;
	while(getline(input, text)) {
		istringstream iss(text);
		string word;
		bool firstmark = true;
		while (iss >> word) {
			if(firstmark)
				firstmark = false;
			else
				cout << ' ';
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("No rule for " + key);
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m) {
	auto iter = m.find(s);
	if(iter == m.end())
		return s;
	else
		return iter -> second;
}