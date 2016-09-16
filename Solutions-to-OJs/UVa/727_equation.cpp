// Xiaoyan Wang 9/16/2016
#include <iostream>
// #include <vector>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

bool isop(const char& c);
int opval(const char& c);

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	cin.ignore();
	cin.ignore();

	// Notice: \10 is equivalent to \n
	string line;
	while(cases--) {
		string result;
		result.reserve(50);
		stack<char> operation;
		while(getline(cin, line)) {
			if(line == "")
				break;
			char input = line[0];
			if(isdigit(input))
				result.push_back(input);
			else if(input == '(')
				operation.push(input);
			else if(input == ')') {
				while(operation.top() != '(') {
					result.push_back(operation.top());
					operation.pop();
				}
				operation.pop();
			}
			else if(isop(input)) {
				while(!operation.empty() && opval(input) <= opval(operation.top())) {
					result.push_back(operation.top());
					operation.pop();
				}
				operation.push(input);
			}
		}
		while(!operation.empty()) {
			result.push_back(operation.top());
			operation.pop();
		}
		cout << result << '\n';
		if(cases)
			cout << '\n';
	}
	cout << flush;
	return 0;
}

inline bool isop(const char& c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int opval(const char& c) {
	switch(c) {
		case '+':
		case '-':
			return 1;
			break; //no necessary
		case '*':
		case '/':
			return 2;
			break;
		case '(':
		case ')':
			return 0;
			break;
		default:
			return -1;
	}
}