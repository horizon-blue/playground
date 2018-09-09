#include <iostream>
using namespace std;

int main() {
    int length;
    cin >> length;
    char prev, curr;
    cin >> prev;
    while(cin >> curr) {
        if(curr != prev) {
            --length;
            cin >> prev;
        } else
            prev = curr;
    }

    cout << length << endl;
    return 0;
}