// Exercise 10.33
//  Write a program that takes the names of an input file and two output
// files. The input file should hold integers. Using an istream_iterator
// read the input file. Using ostream_iterators, write the odd numbers into
// the first output file. Each value should be followed by a space. Write
// the even numbers into the second file. Each of these values should be
// placed on a separate line.
// Xiaoyan Wang 7/20/2016
#include <fstream>
#include <iterator>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  if(argc != 4) {
    cerr << "Incorrect number of arguments." << endl;
    return 1;
  }

  ifstream infile(argv[1]);
  ofstream outfile1(argv[2]), outfile2(argv[3]);
  
  istream_iterator<int> initer(infile), eof;
  ostream_iterator<int> outiter1(outfile1, " "),
    outiter2(outfile2, "\n");
  
  while(initer != eof)
    if(*initer % 2)
      outiter1 = *initer++;
    else
      outiter2 = *initer++;

  return 0;
}
