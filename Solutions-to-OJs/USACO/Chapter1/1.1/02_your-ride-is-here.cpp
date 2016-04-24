/*
ID: skyline12
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a, b;
	fin >> a >> b;
	int anum = 1, bnum = 1;
	for (char c : a)
		anum *= c - 'A' + 1;
	for (char c : b)
		bnum *= c - 'A' + 1;
	if (anum % 47 == bnum % 47)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;
	return 0;
}