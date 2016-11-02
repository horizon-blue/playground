// Xiaoyan Wang 11/1/2016
#include <iostream>
#include <vector>
using namespace std;

bool notPrime[1000000];
vector<int> primes;

void findPrimes();

int main() {
	ios::sync_with_stdio(false);
	findPrimes();
	int n;
	while(cin >> n && n) {
		for(const int& a : primes)
			if(!notPrime[n-a]) {
				cout << n << " = " << a << " + " << n - a << '\n';
				break;
			}
	}

	cout << flush;

	return 0;
}

void findPrimes() {
	// global variables are initialized to 0, which is false
	primes.reserve(78497); 
	notPrime[0] = notPrime[1] = true;
	for(int i = 2; i < 500000; ++i)
		notPrime[2 * i] = true;
	for(int i = 3; i < 1000000; i += 2)
		if(!notPrime[i]) {
			primes.push_back(i);
			int temp = i * 2;
			for(int j = 2; temp < 1000000; ++j) {
				notPrime[temp] = true;
				temp += i;
			}
		}
	// cout << primes.size() << endl; // I get 78497 when running this
}