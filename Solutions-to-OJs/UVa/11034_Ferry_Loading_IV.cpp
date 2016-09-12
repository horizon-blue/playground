// Xiaoyan Wang 9/12/2016
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	while(cases--) {
		int length, carnum;
		cin >> length >> carnum;
		length *= 100; // convert from meter to centimeter
		queue<int> left, right;
		int carlength;
		string position;
		while(carnum--) {
			cin >> carlength >> position;
			if(position[0] == 'l')
				left.push(carlength);
			else
				right.push(carlength);
		}

		// calculate number of times
		bool onleft = true;
		int times = 0;
		int onboard = 0;
		while(!left.empty() || !right.empty()) {
			if(onleft) {
				onboard = 0;
				while(!left.empty() && left.front() + onboard <= length) {
					onboard += left.front();
					left.pop();
				}
				onleft = false;
				++times;
			}
			else {
				onboard = 0;
				while(!right.empty() && right.front() + onboard <= length) {
					onboard += right.front();
					right.pop();
				}
				onleft = true;
				++times;
			}
		}

		cout << times << '\n';
	}

	cout << flush;	

	return 0;
}