// Xiaoyan Wang 10/6/2015
#include <iostream>
#include <string>
using namespace std;

int main() {
	int times;
	cin >> times;
	for (int i = 0; i < times; ++i) {
		string word;
		cin >> word;
		for (int index = 0; index < word.length() / 2; ++index) {
			if (!(index % 2))
				cout << word[index];
		}
		cout << endl;
	}
	return 0;
}