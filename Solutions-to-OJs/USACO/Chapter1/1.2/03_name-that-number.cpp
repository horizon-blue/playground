/*
ID: skyline12
PROG: namenum
LANG: C++11
*/
// Xiaoyan Wang 4/21/2016
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
using std::string;
using std::vector;
using std::ifstream; using std::ofstream;
using std::endl;
using std::unordered_map;
typedef long long ll;

ll translate(const string& name);

unordered_map<char, int> val = {
  {'A', 2}, {'B', 2}, {'C', 2},
  {'D', 3}, {'E', 3}, {'F', 3},
  {'G', 4}, {'H', 4}, {'I', 4},
  {'J', 5}, {'K', 5}, {'L', 5},
  {'M', 6}, {'N', 6}, {'O', 6},
  {'P', 7}, {'R', 7}, {'S', 7},
  {'T', 8}, {'U', 8}, {'V', 8},
  {'W', 9}, {'X', 9}, {'Y', 9}};

int main() {
  ifstream fin("namenum.in"), dicfile("dict.txt");
  ofstream fout("namenum.out");
  unordered_map<ll, vector<string> > dict;

  // processing the names in dict.txt
  string currName;
  while(dicfile >> currName) {
    ll index = translate(currName);
    unordered_map<ll, vector<string> >::iterator it =
      dict.find(index);
    if(it == dict.end())
      dict.insert({index, vector<string>(1, currName)});
    else
      (it -> second).push_back(currName);
  }
  
  ll brandNum;
  fin >> brandNum;

  unordered_map<ll, vector<string> >::iterator it = dict.find(brandNum);
  
  if(it == dict.end())
    fout << "NONE" << endl;
  else
    for(const string& name : it->second)
      fout << name << endl;
  
  fin.close();
  fout.close();
  dicfile.close();

  return 0;
}

ll translate(const string& name) {
  ll value = 0;
  for(int i = 0; i < name.length(); ++i)
    if(name[i] != 'Q' && name[i] != 'Z')
      value = value * 10 + val.at(name[i]);
  return value;
}

