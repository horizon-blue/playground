/*
ID: skyline12
PROG: beads
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;

int count(int position, int BEADS, string NECKLACE) {
  // the cut is before the bead labeled by
  // position. e.g. position = 1 means the
  // cut is between bead 0 and 1
  char rColor = 'w', lColor = 'w';
  int total = 0;

 
  // Right part
  for(int i = position; total < BEADS &&
	(NECKLACE[(i+BEADS)%BEADS] == rColor 
	|| NECKLACE[(i+BEADS)%BEADS] == 'w'
	 || rColor == 'w'); ++i) {
    if(rColor == 'w')
      rColor = NECKLACE[(i+BEADS)%BEADS];
    ++total;
  }

  // Left part
  for(int i = position - 1; total < BEADS &&
	(NECKLACE[(i+BEADS)%BEADS] == lColor 
	|| NECKLACE[(i+BEADS)%BEADS] == 'w'
	 || lColor == 'w'); --i) {
    if(lColor == 'w')
      lColor = NECKLACE[(i+BEADS)%BEADS];
    ++total;
  }

  return total;
}
  
int main() {
  ofstream fout("beads.out");
  ifstream fin("beads.in");
  int BEADS;
  string NECKLACE;
  fin >> BEADS >> NECKLACE;

  int maxCount = 0;
  for(int i = 0; i < BEADS; ++i) {
    int current = count(i, BEADS, NECKLACE);
    if(current > maxCount)
      maxCount = current;
  }

  fout << maxCount << endl;

  return 0;
} 
