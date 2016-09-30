// Xiaoyan Wang 9/30/2016
#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N, k, m;
	while(cin >> N >> k >> m && !(!N && !k && !m)) {
		list<int> people;
		for(int i = 1; i <= N; ++i)
			people.push_back(i);


		auto cclk = people.end();
		auto clk = people.end();
		--cclk;
		// cout << *cclk << ' ' << *clk << endl;
		bool firstround = true;
		while(!people.empty()) {
			if(people.size() == 1) {
				if(!firstround)
					cout << ',';
				cout.width(3);
				cout << people.front();
				break;
			}
			int K = k > people.size()? k % people.size() : k;
			int M = m > people.size()? m % people.size() : m;
			// if(!firstround) {
			// 	--K;
			// 	--M;
			// 	if(K < 0)
			// 		K += k;
			// 	if(M < 0)
			// 		M += m;
			// }
			for(int i = 0; i < K; ++i) {
				++cclk;
				if(cclk == people.end())
					cclk = people.begin(); // back to first people
			}
			for(int i = 0; i < M; ++i) {
				if(clk == people.begin())
					clk = people.end();
				--clk;
			}
			if(firstround)
					firstround = false;
				else
					cout << ',';
			if(clk == people.end())
				clk = people.begin();
			if(cclk == people.end())
				cclk = people.begin();
			if(clk == cclk) {
				cout.width(3);
				cout << *cclk;
				clk = cclk = people.erase(cclk);
				// if(cclk == people.end())
					// cclk = people.begin();
				if(cclk == people.begin())
					cclk = people.end();
				--cclk;
				// if(clk == people.begin())
				// 	clk = people.end();
			}
			else {
				cout.width(3);
				cout << *cclk;
				cout.width(3);
				cout << *clk;
				cclk = people.erase(cclk);
				if(cclk == clk)
					cclk = clk = people.erase(clk);
				else
					clk = people.erase(clk);

				// if(cclk == people.end())
				// 	cclk = people.begin();
				// if(clk == people.begin())
				// 	clk = people.end();
				if(cclk == people.begin())
					cclk = people.end();
				--cclk;
			}
		}
		cout << '\n';
	}
	cout << flush;

	return 0;
}