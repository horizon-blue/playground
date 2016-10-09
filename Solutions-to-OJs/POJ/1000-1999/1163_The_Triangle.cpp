// Xiaoyan Wang 10/8/2016
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int> > tri(2, vector<int>(N));

    int temp;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> temp;
            if(j == 0)
                tri[i&1][j] = temp + tri[(i+1)&1][j];
            else
                tri[i&1][j] = temp + max(tri[(i+1)&1][j-1], tri[(i+1)&1][j]);
        }
    }

    int maxroute = 0;
    for(int i = 0; i < N; ++i)
       if(tri[(N+1)&1][i] > maxroute)
          maxroute =tri[(N+1)&1][i];

    cout << maxroute << endl;

    return 0;
}
