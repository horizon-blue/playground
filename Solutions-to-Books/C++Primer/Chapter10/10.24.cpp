// Exercise 10.24
// Use bind and check_size to find the first element in a vector of ints
// that has a value greater than the length of a specified string value.
// Xiaoyan Wang 7/20/2016
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using placeholders::_1;

bool check_size(const string& s, string::size_type sz);

int main() {
  vector<int> sizes;
  cout << "Enter some numbers:" << endl;
  for(int temp; cin >> temp; sizes.push_back(temp));
  cin.clear();
  string word;
  cout << "Enter a word:" << endl;
  cin >> word;

  auto mark = find_if(sizes.begin(), sizes.end(),
		      bind(check_size, word, _1));

  if(mark != sizes.end())
    cout << "The first int that has a value greater than the "
	 << "length of " << word << " is " << *mark;
  else
    cout << "The int that has a value greater than the length of "
	 << word << " doesn't exist.";
  cout << endl;
  
  return 0;
}

bool check_size(const string& s, string::size_type sz) {
  return s.size() < sz;
}
