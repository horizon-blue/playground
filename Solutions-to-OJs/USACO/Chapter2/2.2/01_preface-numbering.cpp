/*
ID: skyline12
PROG: preface
LANG: C++11
*/
// Xiaoyan Wang 12/30/2016
#include <fstream>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

const string thous[] = {"", "M", "MM", "MMM"};
const string hund[]  = {
    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[] = {
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string unit[] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const string output_order = "IVXLCDM";

unordered_map<char, int> counts;

void add_counts(int num) {
    int temp;
    if(num > 999) {
        temp = num / 1000;
        for(const char& c : thous[temp])
            ++counts[c];
        num -= temp * 1000;
    }
    if(num > 99) {
        temp = num / 100;
        for(const char& c : hund[temp])
            ++counts[c];
        num -= temp * 100;
    }
    if(num > 9) {
        temp = num / 10;
        for(const char& c : tens[temp])
            ++counts[c];
        num -= temp * 10;
    }

    for(const char& c : unit[num])
        ++counts[c];
}

int main() {
    std::ifstream fin("preface.in");
    std::ofstream fout("preface.out");
    int N;
    fin >> N;
    for(int i = 1; i <= N; ++i)
        add_counts(i);

    for(const char& c : output_order)
        if(counts[c])
            fout << c << ' ' << counts[c] << '\n';

    fout << std::flush;
    return 0;
}
