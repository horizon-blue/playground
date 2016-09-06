// Xiaoyan Wang 9/4/2016d
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool issuprising(const string& s);

int main() {
	ios::sync_with_stdio(false);
	string s;
	while(cin >> s && s != "*") {
		if(issuprising(s))
			cout << s << " is surprising.\n";
		else
			cout << s << " is NOT surprising.\n";
	}
	cout << flush;
	return 0;
}

inline size_t tonum(const char& c) {
	return c - 'A';
}

bool issuprising(const string& s) {
	size_t slen = s.length();
	if(slen < 3)
		return true;
	for(size_t n = 1; n < slen - 1; ++n) {
		vector<vector<bool> > exists(26, vector<bool>(26, false));
		for(size_t i = 0; i + n < s.length(); ++i) {
			if(exists[tonum(s[i])][tonum(s[i + n])]) {
				// cout << '\"' << s[i] << s[i+n] << "\" existed\n";
				return false;
			}
			else {
				exists[tonum(s[i])][tonum(s[i + n])] = true;
				// cout << "Add \"" << s[i] << s[i+n] << "\" to existed\n";
			}
		}
		// for(string::iterator it = s.begin(); it + n != s.end(); ++it) {
		// 	pair<iterator, bool> result = set.emplace(it, it + n);
		// 	if(result.second == false) {
		// 		return false;
		// 	}
		// }
	}
	return true;
}