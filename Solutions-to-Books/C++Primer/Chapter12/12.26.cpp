// Exercise 12.26
// Rewrite the program on page 481 using an allocator
// Xiaoyan Wang 8/4/2016
#include <string>
#include <memory>
#include <iostream>
using namespace std;

int main() {
	size_t n;
	cout << "How many string(s) do you wish to enter?" << endl;
	cin >> n;
	allocator<string> alloc;
	auto const q = alloc.allocate(n);
	string *p = q;
	for(string temp; p != q + n && cin >> temp; ++p)
		alloc.construct(p, temp);
	cout << p - q << " string(s) are entered; they are:" << endl;
	for(auto ptr = q; ptr != p; ++ptr) {
		cout << *ptr << endl;
		alloc.destroy(ptr);
	}
	alloc.deallocate(q, n);
	return 0;
}