// Exercise 12.6
// Write a function that returns a dynamically allocated vector of ints. Pass that
// vector to another function that reads the standard input to give values to the
// elements. Pass the vector to another function to print the values that were read.
// Remember to delete the vector at the appropriate time.
// Xiaoyan Wang 8/1/2016
#include <iostream>
#include <vector>
using namespace std;

vector<int>* createVec();
vector<int>* readVec(vector<int> *ivec);
ostream& printVec(vector<int> *ivec);

int main() {
	vector<int> *ivec = createVec();
	readVec(ivec);
	printVec(ivec);
	delete ivec;

	return 0;
}

vector<int>* createVec() {
	return new vector<int>();
}

vector<int>* readVec(vector<int> *ivec) {
	for(int temp; cin >> temp; ivec->push_back(temp))
		;
	return ivec;
}

ostream& printVec(vector<int> *ivec) {
	for(const int &num : *ivec)
		cout << num << ' ';
	return cout;
}