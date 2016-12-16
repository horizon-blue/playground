// Just want to do something super easy to celebrate end of final week
// Xiaoyan Wang 12/16/2016
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    while(cases--) {
        int length, num_ants;
        cin >> length >> num_ants;
        int min_time = 0, max_time = 0;
        int pos;
        while(num_ants--) {
            cin >> pos;
            min_time = max(min_time, min(pos, length - pos));
            max_time = max(max_time, max(pos, length - pos));
        }
        cout << min_time << ' ' << max_time << '\n';
    }
    cout << flush;
    return 0;
}