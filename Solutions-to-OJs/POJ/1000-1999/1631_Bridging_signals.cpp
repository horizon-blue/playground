// Xiaoyan Wang 10/8/2016
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    int cases;
    cin >> cases;
    while(cases--) {
        int size;
        cin >> size;
        vector<int> seq;
        seq.reserve(size + 1);
        seq.push_back(-1);
        int temp;
        for(int i = 0; i < size; ++i) {
            cin >> temp;
            if(temp > seq.back())
                seq.push_back(temp);
            else {
                vector<int>::iterator loc
                    = lower_bound(seq.begin(), seq.end(), temp);
                *loc = temp;
            }
        }
        cout << seq.size() - 1 << '\n';
    }
    cout << flush;
    return 0;
}
