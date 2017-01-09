/*
ID: skyline12
PROG: zerosum
LANG: C++11
*/
// Xiaoyan Wang 01/09/2017
#include <fstream>
// #include <iostream>
#include <string>
using namespace std;

string sol = "1 2 3 4 5 6 7 8 9";
int N;

bool increment(string& s);
bool is_zero(const string& s);

int main() {
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");


    fin >> N;
    while(sol.back() - '0' != N)
        sol.pop_back();

    while(increment(sol)) {
        // fout << "Testing: " << sol << '\n';
        if(is_zero(sol))
            fout << sol << '\n';
    }

    fout << flush;

    return 0;
}

bool increment(string& s) {
    for(int i = s.size() - 2; i > 0; i -= 2) {
        if(s[i] != '-') {
            if(s[i] == ' ')
                s[i] = '+';
            else
                s[i] = '-';
            return true;
        }
        s[i] = ' ';
    }
    return false;
}

bool is_zero(const string& s) {
    char prev_operator = '+';
    int total          = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(i & 1) {
            prev_operator = s[i];
        } else {
            int current_num = s[i] - '0';
            if(current_num != N) {
                int j;
                for(j = i + 1; j < s.size(); ++j) {
                    if(j & 1) {
                        if(s[j] != ' ') {
                            break;
                        }
                    } else
                        current_num = current_num * 10 + s[j] - '0';
                }
                i = j - 1;
            }
            if(prev_operator == '+')
                total += current_num;
            else
                total -= current_num;
        }
    }

    // cout << s << " = " << total << '\n';

    if(total)
        return false;
    else
        return true;
}