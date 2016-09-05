// Xiaoyan Wang 9/4/2016
// UNTESTED
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class LargeInt {
public:
	LargeInt(): value(string(101, 0)) { }
	LargeInt(const string& s): value(s) { }
	LargeInt(int num): value(string(101, 0)) {
		for(int i = 100; i > 0 && num; --i) {
			value[i] = num % 10;
			num /= 10;
		}
	}
	char& operator [] (int index) {
		return value[index];
	}

	char operator [] (int index) const {
		return value[index];
	}

	LargeInt &operator +=(const LargeInt &rhs) {
		int carryout = 0;
		for(int i = 100; i > 0; --i) {
			int temp = value[i] + rhs[i] + carryout;

			// if(temp == 0)
				// break;

			value[i] = temp % 10;
			carryout = temp / 10;
		}
		return *this;
	}

	// friend LargeInt operator +(const LargeInt &lhs, const LargeInt &rhs) {
	// 	LargeInt result();
	// 	int carryout = 0;
	// 	for(int i = 100; i > 0; --i) {
	// 		if(!lhs[i] && !rhs[i] && !carryout)
	// 			break;
	// 		result.value[i] = (lhs[i] + rhs[i] + carryout) % 10;
	// 		carryout = (lhs[i] + rhs[i] + carryout) / 10;
	// 	}
	// 	return result;
	// }

	friend bool operator <(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value < rhs.value;
	}

	friend bool operator ==(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value == rhs.value;
	}	

	friend bool operator >(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value > rhs.value;
	}

	friend bool operator <=(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value <= rhs.value;
	}

	friend bool operator >=(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value >= rhs.value;
	}

	friend bool operator !=(const LargeInt &lhs, const LargeInt &rhs) {
		return lhs.value != rhs.value;
	}

	friend istream& operator >>(istream& is, LargeInt &lg) {
		string temp;
		is >> temp;
		if(temp.length() < 101) {
			lg.value.reserve(101);
			lg.value = string(101 - temp.length(), 0);
			for(int i = 0; i < temp.length(); ++i)
				lg.value.push_back(temp[i] - 48);
		}
		else
			lg.value = temp;
		return is;
	}

	// for debugging purpose
	friend ostream& operator <<(ostream &os, const LargeInt &lg) {
		for(int i = 1; i < 101; ++i)
			os << static_cast<char>(lg.value[i] + 48);
		return os;
	}
private:
	string value;
};

vector<LargeInt> fibs;

void findfibs(int num);

int main() {
	ios::sync_with_stdio(false);
	findfibs(500);
	// cout << LargeInt(1) << endl;
	// cout << "List of fibs: \n";
	// for(int i = 1; i <= 500; ++i)
	// 	cout << fibs[i] << "\n";
	// cout << endl;

	LargeInt a, b;
	LargeInt zero = string(101, 0);
	while(cin >> a >> b && b != zero) {
		int count = 0;
		for(int i = 1; i <= 500; ++i) {
			// cout << fibs[i] << "\n";
			if(fibs[i] < a)
				continue;
			else if(fibs[i] > b)
				break;
			++count;
		}
		cout << count << "\n";
	}
	cout << flush;

	return 0;
}

void findfibs(int num) {
	// fibs = vector<LargeInt>(101, 0);
	fibs.reserve(num+1);
	fibs.push_back(LargeInt());
	fibs.push_back(LargeInt(1));
	fibs.push_back(LargeInt(2));
	// fibs[1] = LargeInt(1);
	// fibs[2] = LargeInt(2);
	for(int i = 3; i <= num; ++i) {
		fibs.push_back(LargeInt());
		fibs[i] += fibs[i-1];
		fibs[i] += fibs[i-2];
	}


}