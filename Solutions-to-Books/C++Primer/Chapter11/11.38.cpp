// Exercise 11.38
// Rewrite the word-counting and word-transformation programs to use an unordered_map.
// Mostly copied from 11.4.cpp (word-counting) and 11.33.cpp (word-transformation)
// Xiaoyan Wang 11/24/2016
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_set>
using namespace std;

void word_counting();
void word_transform();
void process_word(string& word);
void word_transform(ifstream &map_file, ifstream &input);
unordered_map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const unordered_map<string, string> &m);

int main() {
	cout << "Enter 1 for word_counting, 0 for word_transform:" << endl;
	bool option;
	cin >> option;
	if(option)
		word_counting();
	else {
		ifstream map_file("rules"), input("text");
		word_transform(map_file, input);
	}
	return 0;
}

void word_counting() {
  unordered_map<string, size_t> word_count;
  unordered_set<string> exclude = {"the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word) {
    // process word to remove uppercase characters and punctuation
    process_word(word);
    if (exclude.find(word) == exclude.end())
      ++word_count[word];
  }
  
  for (const auto& p : word_count)
    cout << p.first << " occurs " << p.second
	 << ((p.second > 1) ? " times." : " time.") << endl;
}

void word_transform(ifstream &map_file, ifstream &input) {
	unordered_map<string, string> trans_map = buildMap(map_file);
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

unordered_map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("No rule for " + key);
	return trans_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m) {
	auto iter = m.find(s);
	if(iter == m.end())
		return s;
	else
		return iter -> second;
}

void process_word(string& word) {
  for (auto iter = word.begin(); iter != word.end();) {
    if (isupper(*iter)) {
      *iter = tolower(*iter);
      ++iter;
    }
    else if (ispunct(*iter))
      iter = word.erase(iter);
    else
      ++iter;
  }
}