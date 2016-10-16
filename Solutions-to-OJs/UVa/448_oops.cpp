// Xiaoyan Wang 9/30/2016
#include <iostream>
#include <string>
// #include <deque>
#include <iterator>
using namespace std;

istream_iterator<char> iter(cin), the_end;
unsigned chartoint(const char& c);

string operand();

int main() {
	// ios::sync_with_stdio(false);
	while(iter != the_end) {
		if(*iter == '\n') {
			++iter;
			continue;
		}
		char operation = *iter++;
		// cout << "operation = " << operation << endl;
		switch(operation) {
			case '0':
				cout << "ADD " << operand();
				cout << ',' << operand() << '\n'; // seperate into two lines to enfore order of execution
				break;
			case '1':
				cout << "SUB " << operand();
				cout << ',' << operand() << '\n';
				break;
			case '2':
				cout << "MUL " << operand();
				cout << ',' << operand() << '\n';
				break;
			case '3':
				cout << "DIV " << operand();
				cout << ',' << operand() << '\n';
				break;
			case '4':
				cout << "MOV " << operand();
				cout << ',' << operand() << '\n';
				break;
			case '5':
				cout << "BREQ " << operand() << '\n';
				break;
			case '6':
				cout << "BRLE " << operand() << '\n';
				break;
			case '7':
				cout << "BRLS " << operand() << '\n';
				break;
			case '8':
				cout << "BRGE " << operand() << '\n';
				break;
			case '9':
				cout << "BRGR " << operand() << '\n';
				break;
			case 'A':
				cout << "BRNE " << operand() << '\n';
				break;
			case 'B':
				cout << "BR " << operand() << '\n';
				break;
			case 'C':
				cout << "AND " << operand();
				cout << ',' << operand();
				cout << ',' << operand() << '\n';
				break;
			case 'D':
				cout << "OR " << operand();
				cout << ',' << operand();
				cout << ',' << operand() << '\n';
				break;
			case 'E':
				cout << "XOR " << operand();
				cout << ',' << operand();
				cout << ',' << operand() << '\n';
				break;
			case 'F':
				cout << "NOT " << operand() << '\n';
				break;
		}
	}
	cout << flush;
	return 0;
}

string operand() {
	string result;
	char first;
	if(iter == the_end)
		first = '0';
	else if(*iter == '\n') {
		++iter;
	 	first = *iter++;
	 }
	 else
	 	first = *iter++;
	// first -= '0';
	// cout << "First = " << first << endl;
	unsigned firstint = chartoint(first);
	// cout << "firstint = " << (firstint >> 2) << endl;
	switch(firstint >> 2) {
		case 0:
			result.push_back('R');
			break;
		case 1:
			result.push_back('$');
			break;
		case 2:
			result += "PC+";
			break;
	}

	unsigned num = (firstint & 0x3) << 12;
	// cout << "num = " << num << endl;
	for(int i = 8; i >= 0; i -= 4) {
		char temp;
		if(iter == the_end)
			temp = '0';
		else if(*iter == '\n') {
			++iter;
		 	temp = *iter++;
		 }
		 else
		 	temp = *iter++;
		// cout << *iter << endl;
		num |= (chartoint(temp) << i);
		// cout << num << endl;
	}

	return result + to_string(num);
}

inline unsigned chartoint(const char& c) {
	if(c >= '0' && c <= '9')
		return c - '0';
	else if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else
		return c - 'a' + 10;
}