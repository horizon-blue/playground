// Read a set of intergers into a vector
// Print the sum of each pair of adjacent
// elements and the sum of the first and
// last elements and the sum of the second
// and second-to-last, and so on
// Xiaoyan Wang 11/18/2015
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> ivec;
  int temp;
  while(cin >> temp)
    ivec.push_back(temp);
  
  cout << "Sums of the number pairs:" << endl;

  for(decltype(ivec.size()) i = 0; i < ivec.size(); i+=2) {
    if(i == ivec.size()-1)
      cout << ivec[i] << endl;
    else
      cout << ivec[i] + ivec[i+1] << endl;
  }
  
  cout << "Sums of the first and the last elements:" << endl;
  for(decltype(ivec.size()) i = 0; i < ivec.size()/2+1; ++i) {
    if(i == ivec.size()/2 + 1)
      if(!(ivec.size() % 2))
	break;
      else
	cout << ivec[i] << endl;
    cout << ivec[i] + ivec[ivec.size()-1-i] << endl;
  }

  return 0;
}
