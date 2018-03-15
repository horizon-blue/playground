/*
ID: skyline12
PROG: nocows
LANG: C++14
*/
// Xiaoyan Wang 03/14/2018
#include <fstream>
using namespace std;

long long COWS[201][101];


int main() {
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");

    int N, K;
    fin >> N >> K;

    // base case: 1 node
    COWS[1][1] = 1;
    for(int k = 2; k <= K; ++k) {
        for(int n = 2 * k - 1; n <= N; n += 2) {
            for(int i = 1; i <= n - 2; i += 2) {
                for(int j = 1; j < k - 1; ++j) {
                    COWS[n][k] += COWS[n - i - 1][k - 1] * COWS[i][j];
                    COWS[n][k] += COWS[n - i - 1][j] * COWS[i][k - 1];
                }
                COWS[n][k] += COWS[n - i - 1][k - 1] * COWS[i][k - 1];
                COWS[n][k] %= 9901;
            }
        }
    }

    fout << COWS[N][K] << endl;

    return 0;
}