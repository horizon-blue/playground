// The program on page 354 to remove even-valued
// elements and duplicate odd ones will not work
// on a list or forward_list. Why? Revise the
// program so that it works on these types as well.
// Xiaoyan Wang 7/13/2016
#include <list>
#include <forward_list>
#include <iostream>
using namespace std;

int main() {
  list<int> lsti = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  forward_list<int> fwdi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto lstiter = lsti.begin();
  while(lstiter != lsti.end()) {
    if(*lstiter % 2) {
      lstiter = lsti.insert(lstiter, *lstiter);
      ++lstiter;
      ++lstiter;
    }
    else
      lstiter = lsti.erase(lstiter);
  }

  auto prev = fwdi.before_begin(), curr = fwdi.begin();
  while(curr != fwdi.end()) {
    if(*curr % 2) {
      prev = curr = fwdi.insert_after(prev, *curr);
      ++prev;
      ++curr;
      ++curr;
    }
    else
      curr = fwdi.erase_after(prev);
  }

  cout << "contents in list<int>:";
  for(int num : lsti) cout << ' ' << num;
  cout << endl;

  cout << "contents in forward_list<int>:";
  for(int num : fwdi) cout << ' ' << num;
  cout << endl;

  return 0;
}
