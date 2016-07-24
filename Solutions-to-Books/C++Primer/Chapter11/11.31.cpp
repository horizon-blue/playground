// Exercise 11.31
// Write a program that defines a multimap of authors and their works. Use find to find an
// element in the multimap and erase that element. Be sure your program works correctly if the
// element you look for is not in the map.
// Xiaoyan Wang 7/24/2016
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	multimap<string, string> books;
	cout << "Enter the name of the authors and their books:" << endl;
	for (string auth, work; cin >> auth >> work; books.emplace(auth, work));
	cin.clear();

	cout << "Enter the name of the author and the book you want to remove:" << endl;
	string author, work;
	cin >> author >> work;
	for(auto b = books.lower_bound(author), e = books.upper_bound(author); b != e; ++b) 
		if(b -> second == work) {
			books.erase(b);
			break;
		}

	cout << "The remaining books are:" << endl;
	for(const auto& book : books)
		cout << book.first << ' ' << book.second << endl;

	return 0;
}