// Xiaoyan Wang 9/7/2016
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin.ignore(256, '\n');
	for(int i = 0; i < n; ++i) {
		string line1, line2;
		getline(cin, line1);
		getline(cin, line2);
		int mark1 = -1, len1 = 0, mark2 = -1, len2 = 0;
		for(int j = 0; j < line1.length(); ++j) {
			if(line1[j] == '<') {
				if(mark1 == -1) {
					mark1 = j + 1;
					for(int k = mark1; k < line1.length(); ++k) {
						if(line1[k] == '>') {
							j = k;
							break;
						}
						++len1;
					}
				}
				else {
					mark2 = j + 1;
					for(int k = mark2; k < line1.length(); ++k) {
						if(line1[k] == '>') {
							j = k;
							break;
						}
						++len2;
					}
				}
			}
		}
		// cout << line1 << ' ' << line2 << endl;
		// cout << "mark1 = " << mark1 << ", mark2 = " << mark2 << endl;
		// cout << line1.substr(mark1, len1) << endl;
		cout << line1.substr(0, mark1 - 1) << line1.substr(mark1, len1)
		<< line1.substr(mark1 + len1 + 1, mark2 - mark1 - len1 - 2) << line1.substr(mark2, len2)
		<< line1.substr(mark2 + len2 + 1, line2.length() - mark2 - len2) << '\n';
		cout << line2.substr(0, line2.length() - 3) << line1.substr(mark2, len2)
		<< line1.substr(mark1 + len1 + 1, mark2 - mark1 - len1 - 2) << line1.substr(mark1, len1)
		<< line1.substr(mark2 + len2 + 1, line2.length() - mark2 - len2) << '\n';
	}
	cout << flush;
	return 0;
}