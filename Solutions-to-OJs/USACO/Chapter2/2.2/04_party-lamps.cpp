/*
ID: skyline12
PROG: lamps
LANG: C++11
*/
// Xiaoyan Wang 12/30/2016
// notice that pressing a single button twice is equivalent to not pressing at
// all, also notice that the order of pressing button won't affect the final
// result. Therefore, there are at most 2^4 = 16 different state of lamps.
// #include <bitset>
#include <algorithm>
#include <fstream>
#include <unordered_set>
// #include <set>
#include <string>
#include <vector>
using namespace std;

// vector<bitset<6>> final_states = {0x3f, 0x1b, 0x2a, 0xe, 0x15, 0x31, 0x0,
// 0x24};
vector<string> states = {"111111",
                         "011011",
                         "101010",
                         "001110",
                         "010101",
                         "110001",
                         "000000",
                         "100100"};
// what is impossible when number of press is less than 3
vector<vector<int>> press_map = {{1, 2, 3, 4, 5, 6, 7}, {0, 3, 5, 7}, {1}};
// if number of press is greater than 3, then all combinations are possible


int main() {
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    int N, count;
    fin >> N >> count;
    unordered_set<int> lights_on;
    unordered_set<int> lights_off;
    for(int temp; fin >> temp && temp != -1; lights_on.insert((--temp) % 6))
        ;
    for(int temp; fin >> temp && temp != -1; lights_off.insert((--temp) % 6))
        ;

    if(count < 3) {
        for(const int& i : press_map[count])
            states[i] = "del";
    }

    // verify
    for(string& s : states) {
        if(s[0] == 'd')
            continue;
        for(const int& i : lights_on)
            if(s[i] == '0') {
                s = "del";
                continue;
            }
        for(const int& i : lights_off)
            if(s[i] == '1') {
                s = "del";
                continue;
            }
    }

    sort(states.begin(), states.end());

    // printing result
    int num_loop = N / 6;
    int rem      = N - num_loop * 6;

    for(int i = 0; i < states.size(); ++i) {
        if(states[i][0] == 'd') {
            if(i == 0)
                fout << "IMPOSSIBLE\n";
            break;
        }
        for(int j = 0; j < num_loop; ++j)
            fout << states[i];
        fout << states[i].substr(0, rem) << '\n';
    }

    fout << flush;


    return 0;
}