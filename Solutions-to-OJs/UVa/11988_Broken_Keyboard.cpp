// Xiaoyan Wang 9/10/2016
#include <iostream>
#include <deque>
#include <string>
// #include <iterator>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string temp;
	while(getline(cin, temp)) {
		deque<string> output;
		// insert_iterator<deque<string>> itout(output, output.end());
		bool pressedHome = false;
		auto beg = temp.begin();
		for(auto curr = beg; curr != temp.end(); ++curr) {
			if(*curr == '[') {
				if(pressedHome)
					output.emplace_front(beg, curr);
				else
					output.emplace_back(beg, curr);
				pressedHome = true;
				beg = curr;
				++beg;
			}
			else if(*curr == ']') {
				if(pressedHome)
					output.emplace_front(beg, curr);
				else
					output.emplace_back(beg, curr);
				pressedHome = false;
				beg = curr;
				++beg;
			}
		}
		if(pressedHome)
			output.emplace_front(beg, temp.end());
		else
			output.emplace_back(beg, temp.end());

		for(const auto &s : output)
			cout << s;
		cout << "\n";
	}
	cout << flush;
	return 0;
}