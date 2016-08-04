// Exercise 12.20
// Write a program that reads an input file a line at a time into a StrBlob and
// uses a StrBlobPtr to print each element in that StrBlob.
// Xiaoyan Wang 8/4/2016
#include <fstream>
#include <iostream>
#include <string>
#include "12.19.cpp"
using namespace std;

int main() {
	ifstream fin("12.20.txt");
	StrBlob sb;
	for(string temp; getline(fin, temp); sb.push_back(temp))
		;
	fin.close();
	for(StrBlobPtr sbptr = sb.begin(); !isequal(sbptr, sb.end()); sbptr.incr())
		cout << sbptr.deref() << endl;
	return 0;
}