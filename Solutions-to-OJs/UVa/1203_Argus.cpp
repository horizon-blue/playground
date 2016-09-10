// Xiaoyan Wang 9/10/2016
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Register {
	Register() = default;
	Register(istream& is) {
		is >> qnum >> period;
		nexttime = period;
	}
	int qnum;
	int period;
	int nexttime;
};

bool operator <(const Register& lhs, const Register& rhs) {
	if(lhs.nexttime == rhs.nexttime)
		return lhs.qnum > rhs.qnum;
	return lhs.nexttime > rhs.nexttime; // to reverse the order
}

int main() {
	string checker;
	priority_queue<Register> rq;
	while(cin >> checker && checker[0] != '#')
		rq.emplace(cin);

	int num;
	cin >> num;

	while(num--) {
		Register fastest = rq.top();
		cout << fastest.qnum << '\n';
		rq.pop();
		fastest.nexttime += fastest.period;
		rq.push(fastest);
	}

	cout << flush;

	return 0;
}