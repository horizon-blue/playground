// Xiaoyan Wang 9/4/2016
// UNTESTED
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;


// struct strcompare {
// 	bool operator () (const string& a, const string& b) const {
// 		if(a.length() == b.length())
// 			return a < b;
// 		else
// 			return a.length() < b.length();
// 	}
// };

int process(set<string> &sset);


int main() {
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n && n) {
		set<string> sset;
		bool repeated = false;
		int shortestlength = 100;
		for(int i = 0; i < n; ++i) {
			string temp;
			cin >> temp;
			if(repeated)
				continue;
			if(temp.length() < shortestlength)
				shortestlength = temp.length();
			// if(sset.emplace(temp.rbegin(), temp.rend())second == false) POJ does not suport c++ 11
			if(sset.insert(string(temp.rbegin(), temp.rend())).second == false)
				repeated = true;
		}
		if(repeated || sset.size() == 1)
			cout << 0 << '\n';
		else {
			// for(set<string>::iterator it1 = sset.begin(); it1 != sset.end(); ++it1)
			// 	cout << *it1 << endl;
			int result = process(sset);
			if(result > shortestlength - 1)
				result = shortestlength - 1;
			cout << result << '\n';
		}
	}
	cout << flush;

	return 0;
}


int process(set<string> &sset) {
	int result = 100;
	for(set<string>::iterator it1 = sset.begin(), it2 = it1; ++it2 != sset.end(); ++it1) {
		if(it1 -> length() != it2 -> length())
			continue;
		int i;
		for(i = 0; i < it1->length(); ++i) {
			if((*it1)[i] != (*it2)[i])
				break;
		}
		// cout << "*it1 = " << *it1 << ", *it2 = " << *it2 << "\n";
		// cout << "i = " << i << "\n";
		if((it1 -> length()) - i - 1 < result)
			result = (it1 -> length()) - i - 1;
	}
	return result;
}