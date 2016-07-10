// Exercise 7.23
// Write your own version of the Screen class.
// Exercise 7.24
// Give your Screen class three constructors: a default constructor;
// a constructor that takes values for height and width and
// initializes the contents to hold the given number of blanks;
// and a constructor that takes values for height, width, and a
// character to use as the contents of the screen
// Xiaoyan Wang 3/17/2016
#include <string>

class Screen {
public:
  // type alias for std::string::size_type
  typedef std::string::size_type pos;
  Screen() = default;  // default constructor
  Screen(pos ht, pos wd): height(ht), width(wd),
			  contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c): height(ht), width(wd),
				  contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }  // implicitly inline
  inline char get(pos ht, pos wd) const;  // explicitly inline
  Screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

inline Screen& Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}
