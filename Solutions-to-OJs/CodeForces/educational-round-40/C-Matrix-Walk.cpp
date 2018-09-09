#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

long long x = 1;
long long y = 1;

int main() {
    long long n;
    vector<long long> path;
    cin >> n;
    path.reserve(n);
    for(long long curr; cin >> curr; path.push_back(curr))
        ;

    // find y (if any)
    for(long long i = 1; i != n; ++i) {
        if(path[i] == path[i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
        long long dist = abs(path[i - 1] - path[i]);
        if(dist != 1) {
            y = dist;
            break;
        }
    }

    // calculate x
    long long curr_x = (path[0] - 1) / y + 1;
    if(curr_x > x)
        x = curr_x;

    for(long long i = 1; i != n; ++i) {
        long long dist = abs(path[i - 1] - path[i]);
        // check whether it is valid
        if(!((dist == 1 && (max(path[i], path[i - 1]) - 1) % y) || dist == y)) {
            // invalid
            cout << "NO" << endl;
            return 0;
        }
        // calculate x
        long long curr_x = (max(path[i], path[i - 1]) - 1) / y + 1;
        if(curr_x > x)
            x = curr_x;
    }

    cout << "YES\n" << x << ' ' << y << endl;

    return 0;
}