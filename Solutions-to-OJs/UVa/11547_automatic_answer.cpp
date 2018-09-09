// Xiaoyan Wang 09/08/2018
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int cases, n;
    cin >> cases;
    while(cases--) {
        cin >> n;
        cout << abs(((((((n * 567) / 9) + 7492) * 235) / 47 - 498) / 10) % 10)
             << endl;
    }
    return 0;
}