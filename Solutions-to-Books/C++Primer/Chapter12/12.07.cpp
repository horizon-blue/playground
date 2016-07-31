// Exercise 12.7
// Redo the previous exercise, this time using shared_ptr
// Mostly copied from 12.06.cpp
// Xiaoyan Wang 8/1/2016
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
typedef shared_ptr<vector<int>> vecptr;

vecptr createVec();
vecptr readVec(vecptr ivec);
ostream& printVec(vecptr ivec);

int main() {
	vecptr ivec = createVec();
	readVec(ivec);
	printVec(ivec);

	return 0;
}

vecptr createVec() {
	return make_shared<vector<int>>();
}

vecptr readVec(vecptr ivec) {
	for(int temp; cin >> temp; ivec->push_back(temp))
		;
	return ivec;
}

ostream& printVec(vecptr ivec) {
	for(const int &num : *ivec)
		cout << num << ' ';
	return cout;
}