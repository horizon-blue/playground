/*
ID: skyline12
PROG: subset
LANG: C++11
*/
// Xiaoyan Wang 12/30/2016
#include <fstream>
using std::endl;

long long mem[41][400] = {0};

int main() {
    std::ifstream fin("subset.in");
    std::ofstream fout("subset.out");
    int N, target;
    fin >> N;
    target = (N * (N + 1)) >> 1;
    if(target & 1) {  // sum is odd, no possible subset
        fout << 0 << endl;
        return 0;
    }
    target >>= 1;
    mem[N + 1][0] = 1;
    for(int i = N; i > 0; --i) {
        mem[i][0] = 1;
        for(int j = i; j <= target; ++j) {
            mem[i][j] = mem[i + 1][j - i] + mem[i + 1][j];
            // fout << i << ' ' << j << ' ' << mem[i][j] << '\n';
        }
    }
    fout << mem[1][target] / 2 << endl;
    return 0;
}