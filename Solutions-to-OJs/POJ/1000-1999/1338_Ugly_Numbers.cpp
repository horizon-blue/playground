// Xiaoyan Wang 9/7/2016
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> uglynums(1501, 0);

void findnums();

int main() {
	ios::sync_with_stdio(false);
	findnums();
	int n;
	while(cin >> n && n)
		cout << uglynums[n] << '\n';
	cout << flush;
	return 0;
}

void findnums() {
	for(int i = 0; i <= 5; ++i)
		uglynums[i] = i;

	int loc2 = 0, loc3 = 0, loc5 = 0;
	for(int i = 6; i <= 1500; ++i) {
		for(; uglynums[loc2]*2 <= uglynums[i-1]; ++loc2);
		for(; uglynums[loc3]*3 <= uglynums[i-1]; ++loc3);
		for(; uglynums[loc5]*5 <= uglynums[i-1]; ++loc5);
		uglynums[i] = min(min(uglynums[loc2]*2, uglynums[loc3]*3), uglynums[loc5]*5);
	}
// 	for(int i = 0; i <= 1500; ++i)
// 		cout << uglynums[i] << endl;
}

