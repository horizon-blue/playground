// Exercise 7.53
// Define your own version of Debug.
// Xiaoyan Wang 3/24/2016
#include <iostream>

class Debug {
public:
  constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o):
    hw(h), io(i), other(o) {}
  // Add a trailing const after the parameter list (comparing
  // to the book) since in C++ 14 constexpr will not imply
  // const
  constexpr bool any() const { return hw || io || other; }
  void set_io(bool b) { io = b; }
  void set_hw(bool b) { hw = b; }
  void set_other(bool b) { other = b; }

private:
  bool hw;     // hardware errors other than IO errors
  bool io;     // IO errors
  bool other;  // other errors
};

// Testing
int main() {
  using std::cerr;
  using std::endl;
  
  constexpr Debug io_sub(false, true, false);  // debugging IO
  if (io_sub.any()) // should be equivalent to if(true)
    cerr << "print appropriate error message" << endl;
  constexpr Debug prod(false); // no debugging during production
  if (prod.any())  // should be equivalent to if(false)
    cerr << "print an error message" << endl;

  return 0;
}
