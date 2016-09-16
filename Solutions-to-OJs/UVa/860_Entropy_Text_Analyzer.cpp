// Xiaoyan Wang 9/15/2016
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void print_result(const unordered_map<string, int>& dict, size_t lambda);
bool ismark(const char& c);

int main() {
	ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(1);
	string line;
	unordered_map<string, int> dict;
	size_t lambda = 0;
	for(;;) {
		getline(cin, line);
		while(line != "" && line[0] == '*' && line == "****END_OF_TEXT****") {
			print_result(dict, lambda);
			getline(cin, line);
			if(line != "" && line[0] == '*' && line == "****END_OF_INPUT****") {
				cout << flush;
				return 0;
				break;
			}
			dict.clear();
			lambda = 0;
		}

		// process the line
		for(char &c : line) {
			if(ismark(c))
				c = ' ';
			else
				c = tolower(c);
		}

		istringstream iss(line);
		string word;
		while(iss >> word) {
			++lambda;
			++dict[word];
		}
	}
}

void print_result(const unordered_map<string, int>& dict, size_t lambda) {
	double emax = log10(lambda);
	double et = 0;
	for(const auto& p : dict)
		et += p.second * log10(lambda / static_cast<double>(p.second));
	if(lambda)
		et /= static_cast<double>(lambda);
	else
		et = 0;
	double erel = et * 100 / emax;
	cout << lambda << ' ' << et << ' ' << static_cast<int>(erel + 0.5) << '\n';
}

inline bool ismark(const char& c) {
	return c == ',' || c == '.' || c == ':' || c == ';' || c == '!'
			|| c == '?' || c == '\"' || c == '(' || c == ')';
}