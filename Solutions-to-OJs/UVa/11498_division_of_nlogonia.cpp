// Xiaoyan Wang 09/08/2018
#include <iostream>
using namespace std;

int main() {
    int cases, X, Y, x, y;
    for(cin >> cases; cases; cin >> cases) {
        cin >> X >> Y;
        while(cases--) {
            cin >> x >> y;
            if(x == X || y == Y)
                cout << "divisa\n";
            else if(x > X) {
                if(y > Y)
                    cout << "NE\n";
                else
                    cout << "SE\n";
            } else {
                if(y > Y)
                    cout << "NO\n";
                else
                    cout << "SO\n";
            }
        }
    }
    cout << flush;

    return 0;
}