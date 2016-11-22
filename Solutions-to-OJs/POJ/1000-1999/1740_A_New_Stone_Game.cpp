// Xiaoyan Wang 11/22/2016
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int num;
    while(cin >> num && num) {
        if(num & 1) {  // if the number of piles is odd
            int garbage;
            while(num--)
                cin >> garbage;
            cout << 1 << endl;
            continue;
        }
        // the number of piles is even
        vector<int> piles;
        piles.reserve(num);
        int temp;
        while(num--) {
            cin >> temp;
            piles.push_back(temp);
        }
        sort(piles.begin(), piles.end());
        bool fail = true;
        for(int i = 0; i < piles.size(); i += 2)
            if(piles[i] != piles[i + 1]) {
                fail = false;
                break;
            }
        if(fail)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}