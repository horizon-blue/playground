// Exercise 9.28
// Write a function that takes a forward_list<string>
// and two additional string arguments. The function
// should find the first string and insert the second
// immediately following the first. If the first string
// is not found, then insert the second string at the
// end of the list
// Xiaoyan Wang 7/13/2016
#include <string>
#include <forward_list>
#include <iostream>
using namespace std;

// The function
void combine_strings(forward_list<string>& sfwd,
		     const string& s1, const string& s2) {
  
  for(auto prev = sfwd.before_begin(), curr = sfwd.begin();;
      ++prev, ++curr) {
    if(curr == sfwd.end()) {
      sfwd.insert_after(prev, s2);
      return;
    }
    else if(*curr == s1) {
      sfwd.insert_after(curr, s2);
      return;
    } 
  }
}

// a test
int main() {
  forward_list<string> sfwd;
  cout << "Enter the contents of forward_list<string>,"
       << " enter \"q\" to quit.\n";
  for(string temp; cin >> temp && temp != "q"; sfwd.push_front(temp));

  string s1, s2;
  cout << "Enter string s1:\n";
  cin >> s1;
  cout << "Enter string s2:\n";
  cin >> s2;

  cout << endl;
  cout << "Contents in foward_list<string> before inserting s2:";
  for(const string& temp : sfwd)
    cout << ' ' << temp;
  cout << endl;

  combine_strings(sfwd, s1, s2);
  
  cout << "Contents in foward_list<string> after inserting s2:";
  for(const string& temp : sfwd)
    cout << ' ' << temp;
  cout << endl;

  return 0;
}
