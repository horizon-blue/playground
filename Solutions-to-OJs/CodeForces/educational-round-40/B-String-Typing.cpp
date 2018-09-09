#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    string line;
    cin >> length;
    cin.ignore(256, '\n');
    getline(cin, line);
    // find the longest duplicate prefix via brute force
    for(int n = length / 2; n >= 2; --n) {
        bool isequal = true;
        for(int i = 0; i < n; ++i) {
            if(line[i] != line[n + i]) {
                isequal = false;
                break;
            }
        }
        if(isequal) {
            length -= n - 1;
            break;
        }
    }

    cout << length << endl;


    return 0;
}