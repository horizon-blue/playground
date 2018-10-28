// Xiaoyan Wang 10/17/2018
#include <iostream>
using namespace std;

int sol[21][21][21];

int w(int a, int b, int c) {
    if(a < 0 || b < 0 || c < 0)
        a = b = c = 0;
    else if(a > 20 || b > 20 || c > 20)
        a = b = c = 20;
    return sol[a][b][c];
}


void prefill();

int main() {
    // precalculate the solution
    prefill();
    // read inputs
    int a, b, c;
    while(cin >> a >> b >> c) {
        if(a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
             << endl;
    }
    return 0;
}

void prefill() {
    for(int i = 0; i < 21; ++i) {
        for(int j = 0; j < 21; ++j) {
            for(int k = 0; k < 21; ++k) {
                if(i == 0 || j == 0 || k == 0)
                    sol[i][j][k] = 1;
                else if(i < j && j < k)
                    sol[i][j][k] = sol[i][j][k - 1] + sol[i][j - 1][k - 1] -
                                   sol[i][j - 1][k];
                else
                    sol[i][j][k] = sol[i - 1][j][k] + sol[i - 1][j - 1][k] +
                                   sol[i - 1][j][k - 1] -
                                   sol[i - 1][j - 1][k - 1];
            }
        }
    }
}