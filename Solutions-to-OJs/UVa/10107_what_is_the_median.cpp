// Xiaoyan Wang 09/25/2018
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> s_half;
    priority_queue<int, vector<int>, greater<int>> g_half;
    int num, N = 0;
    int a;  // store the first num
    while(cin >> num) {
        ++N;
        if(N == 1) {
            a = num;
            cout << num << endl;
        } else if(N == 2) {
            cout << (a + num) / 2 << endl;
            if(a > num)
                swap(a, num);
            s_half.push(a);
            g_half.push(num);
        } else {
            if(num <= s_half.top()) {
                if(s_half.size() == g_half.size()) {
                    g_half.push(s_half.top());
                    s_half.pop();
                }
                s_half.push(num);
            } else if(num >= g_half.top()) {
                if(s_half.size() == g_half.size() - 1) {
                    s_half.push(g_half.top());
                    g_half.pop();
                }
                g_half.push(num);
            } else {
                if(s_half.size() == g_half.size()) {
                    g_half.push(num);
                } else {
                    s_half.push(num);
                }
            }
            if(s_half.size() == g_half.size())
                cout << (s_half.top() + g_half.top()) / 2 << endl;
            else
                cout << g_half.top() << endl;

            // cout << s_half.top() << ' ' << g_half.top() << endl;
        }
        // cout << s_half.size() << ' ' << g_half.size() << endl;
    }
    return 0;
}