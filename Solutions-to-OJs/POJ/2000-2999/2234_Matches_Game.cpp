// Xiaoyan Wang 11/22/2016
// A simple Nim Game
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int num;

    while(cin >> num) {
        int result = 0;
        int temp;
        while(num--) {
            cin >> temp;
            result ^= temp;
        }
        if(result)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}