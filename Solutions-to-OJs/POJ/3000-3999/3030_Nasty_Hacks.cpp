// Xiaoyan Wang 9/4/2016
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	for(int i = 0; i < cases; ++i) {
		int r, e, c;
		cin >> r >> e >> c;
		if(e - r > c)
			cout << "advertise\n";
		else if(e - r < c)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}
	cout << flush;
	return 0;

}