// Xiaoyan Wang 09/08/2018
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int one, two, three, four, five, six;
    while(true) {
        cin >> one >> two >> three >> four >> five >> six;
        if(one + two + three + four + five + six == 0)
            break;

        // initialize total number = number of 6x6 packages
        int total = six;
        // handle fives - which can be put together with ones
        one = max(0, one - five * 11);
        total += five;

        // handle four - with one or two
        if(four > 0) {
            total += four;
            if(four * 5 <= two) {
                two -= four * 5;
            } else {
                four -= two / 5 + 1;
                two %= 5;
                one = max(0, one - (20 - 4 * two) - four * 20);
                two = 0;
            }
        }


        // handle three
        if(three > 0) {
            total += three / 4;
            three %= 4;
            if(three > 0) {
                ++total;
                // remaining twos to fit
                int twos = min(two, 1 + 2 * (3 - three));
                one      = max(0, one - (36 - three * 9 - twos * 4));
                two -= twos;
            }
        }


        if(two > 0) {
            total += two / 9;
            two %= 9;
            if(two > 0) {
                ++total;
                one -= 36 - 4 * two;
            }
        }


        if(one > 0) {
            total += one / 36;
            one %= 36;
            if(one > 0)
                ++total;
        }


        cout << total << endl;
    }
    return 0;
}