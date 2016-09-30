// Xiaoyan Wang 9/28/2016
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void word_generator(const vector<string>& dict, const string& rule,
	vector<string>& output);

int main() {
	ios::sync_with_stdio(false);
	int dictsize, rulesize;
	while(cin >> dictsize) {
		vector<string> dict;
		dict.reserve(dictsize);
		string temp;
		for(int i = 0; i < dictsize; ++i) {
			cin >> temp;
			dict.push_back(temp);
		}
		cin >> rulesize;
		vector<string> rules;
		rules.reserve(rulesize);
		for(int i = 0; i < rulesize; ++i) {
			cin >> temp;
			rules.push_back(temp);
		}


		cout << "--\n";

		for(const string& r : rules) {
			// cout << r << endl;
			vector<string> output;
			output.reserve(rules.size());
			// for(const char& c)
			// 	output.emplace_back({c});
			word_generator(dict, r, output);
		}
	}
	cout << flush;
	return 0;
}

void word_generator(const vector<string>& dict, const string& rule,
	vector<string>& output) {
	if(output.size() == rule.length()) {
		for(const string& s : output)
			cout << s;
		cout << '\n';
		return;
	}

	auto loc = output.size();
	// cout << "loc = " << loc << endl;
	if(rule[loc] == '#') {
		for(const string& s : dict) {
			output.emplace_back(s);
			word_generator(dict, rule, output);
			output.pop_back();
		}
	}
	else {
		for(char c = '0'; c <= '9'; ++c) {
			output.emplace_back(string{c});
			word_generator(dict, rule, output);
			output.pop_back();
		}
	}
}