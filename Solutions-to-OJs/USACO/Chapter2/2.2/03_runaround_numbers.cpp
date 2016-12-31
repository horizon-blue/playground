/*
ID: skyline12
PROG: runround
LANG: C++11
*/
// Xiaoyan Wang 12/30/2016
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

bool is_unique(const string& s);
bool is_round_around(string&& s);

int main() {
    std::ifstream fin("runround.in");
    std::ofstream fout("runround.out");
    unsigned long base;
    fin >> base;
    string temp;
    for(unsigned long i = base + 1;; ++i) {
        temp = std::to_string(i);
        if(!is_unique(temp))
            continue;
        if(is_round_around(std::move(temp))) {
            fout << i << std::endl;
            break;
        }
    }

    return 0;
}

bool is_unique(const string& s) {
    vector<bool> visited_digit(9, false);
    int temp;
    for(const char& c : s) {
        temp = c - '0';
        if(!temp || visited_digit[--temp])  // 0 is present
            return false;
        visited_digit[temp] = true;
    }
    return true;
}

bool is_round_around(string&& s) {
    int currloc     = 0;
    int remain_move = s.size();
    int currdig;
    while(remain_move) {
        if(s[currloc] == '*')
            return false;
        currdig    = s[currloc] - '0';
        s[currloc] = '*';
        --remain_move;
        currloc = (currloc + currdig) % s.size();
    }
    if(currloc == 0)
        return true;
    return false;
}