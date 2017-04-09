// Google Code Jam 2017 Qualification Run
// Xiaoyan Wang 04/07/2017
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; ++i) {
        string num;
        cin >> num;
        deque<char> cdeque;
        cdeque.push_back(num[0]);
        int j = 1;
        for(; j < num.size(); ++j) {
            if(num[j] < cdeque.back()) {
                --cdeque.back();
                for(int l  = j; l < num.size(); ++l)
                    num[l] = '9';
                break;
            }
            else
            	cdeque.push_back(num[j]);
        }
        for(j -= 1; j >= 0; --j) {
            int temp = cdeque.back();
            cdeque.pop_back();
            if(!cdeque.empty() && temp < cdeque.back()) {
                num[j] = '9';
                --cdeque.back();
            } else
                num[j] = temp;
        }

        // Remove zeros in the front
        int l;
        for(l = 0; l < num.size(); ++l)
        	if(num[l] != '0')
        		break;
        cout << "Case #" << i << ": " << num.substr(l) << '\n';
    }
    cout << flush;

    return 0;
}