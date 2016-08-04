// Exercise 12.23
// Write a program to concatenate two string literals, putting the result in a dynamically
// allocated array of char. Write a program to concatenate two library strings that have
// the same value as the literals used in the first program. 
// Xiaoyan Wang 8/4/2016
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	char *concat = new char[strlen("hello, ") + strlen("world") + 1];
	strcpy(concat, "hello, ");
	strcat(concat, "world");
	cout << concat << endl;
	delete [] concat;

	string s1 = "hello, ", s2 = "world";
	cout << s1 + s2 << endl;

	return 0;
}