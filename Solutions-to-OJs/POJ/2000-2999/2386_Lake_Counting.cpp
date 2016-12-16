// Another super easy problem
// Xiaoyan Wang 12/16/2016
#include <iostream>
using namespace std;

char land[100][100];
int row, col;

void unmarkWater(const int& r, const int& c);

int main() {
    ios::sync_with_stdio(false);
    cin >> row >> col;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            cin >> land[i][j];

    int result = 0;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            if(land[i][j] == 'W') {
                unmarkWater(i, j);
                ++result;
            }

    cout << result << endl;
    return 0;
}

void unmarkWater(const int& r, const int& c) {
    land[r][c] = '.';
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            int new_r = r + i, new_c = c + j;
            if(new_r < 0 || new_r >= row || new_c < 0 || new_c >= col ||
               land[new_r][new_c] != 'W')
                continue;
            unmarkWater(new_r, new_c);
        }
    }
}