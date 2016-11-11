// Xiaoyan Wang 11/9/2016
#include <iostream>
using namespace std;

unsigned G[1001][1001];

void print_grid(int x, int y);

int main( ) {
    ios::sync_with_stdio(false);
    int cases;
    int m, n, k;
    cin >> cases;
    while(cases--) {
        cin >> m >> n >> k;
        G[m][n] = 1;
        for(int i       = 1; i <= m; ++i)
            G[m - i][n] = 1;
        for(int j       = 1; j <= n; ++j)
            G[m][n - j] = 1;

        for(int i = m - 1; i >= 0; --i)
            for(int j = n - 1; j >= 0; --j) {
                G[i][j] = G[i + 1][j] + G[i][j + 1];
                if(G[i][j] >= k)
                    G[i][j] %= k;
            }

        // // debug
        // print_grid(m, n);
        cout << G[0][0] << '\n';
    }

    cout << endl;

    return 0;
}

void print_grid(int x, int y) {
    for(int i = 0; i <= x; ++i) {
        for(int j = 0; j <= y; ++j)
            cout << G[i][j] << ' ';
        cout << '\n';
    }
}