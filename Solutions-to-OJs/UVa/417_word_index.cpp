// Xiaoyan Wang 9/10/2016
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> dict;
void generate_numbers();

int main() {
	ios::sync_with_stdio(false);
	generate_numbers();
	string input;
	while(cin >> input) {
		auto loc = dict.find(input);
		if(loc != dict.end())
			cout << loc -> second << "\n";
		else
			cout << "0\n";
	}

	cout << flush;

	return 0;
}

void generate_numbers() {
	dict.reserve(83681);
	int no = 0;
	for(char i = 'a'; i <= 'z'; ++i)
		dict.emplace(string{i}, ++no);

	for(char i = 'a'; i <= 'z'; ++i)
		for(char j = i + 1; j <= 'z'; ++j)
			dict.emplace(string{i, j}, ++no);
	
	for(char i = 'a'; i <= 'z'; ++i)
		for(char j = i + 1; j <= 'z'; ++j)
			for(char k = j + 1; k <= 'z'; ++k)
				dict.emplace(string{i, j, k}, ++no);

	for(char i = 'a'; i <= 'z'; ++i)
		for(char j = i + 1; j <= 'z'; ++j)
			for(char k = j + 1; k <= 'z'; ++k)
				for(char l = k + 1; l <= 'z'; ++l)
					dict.emplace(string{i, j, k, l}, ++no);

	for(char i = 'a'; i <= 'z'; ++i)
		for(char j = i + 1; j <= 'z'; ++j)
			for(char k = j + 1; k <= 'z'; ++k)
				for(char l = k + 1; l <= 'z'; ++l)
					for(char m = l + 1; m <= 'z'; ++m)
						dict.emplace(string{i, j, k, l, m}, ++no);
}