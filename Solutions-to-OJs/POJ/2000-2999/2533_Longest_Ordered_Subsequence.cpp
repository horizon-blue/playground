// Xiaoyan Wang 10/8/2016
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> seq;
    seq.reserve(N + 1);
    seq.push_back(-1);
    int temp;
    for(int i = 1; i <= N; ++i) {
        cin >> temp;
        seq.push_back(temp);
    }
    vector<vector<int> > los(N+2, vector<int>(N+2));
    for(int i = 0; i <= N+1; ++i)
        los[i][N+1] = 0;

    for(int j = N; j >= 1; --j)
       for(int i = 0; i < j; ++i) {
          if(seq[i] >= seq[j])
             los[i][j] = los[i][j+1];
          else
             los[i][j] = max(los[i][j+1], 1+los[j][j+1]);
       }

    cout << los[0][1] << endl;

    return 0;
}
