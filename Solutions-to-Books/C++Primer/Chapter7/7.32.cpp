// Exercise 7.32
// Define your own versions of Screen and Window_mgr in which
// clear is a member of Window_mgr and a friend of Screen
// Xiaoyan Wang 3/23/2016
#include <string>
#include <iostream>
#include <vector>
// Mostly copied from 7.27.cpp

class Screen;

class Window_mgr {
public:
  // location ID for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // reset the Screen at the given position to all blanks
  void clear(ScreenIndex);
private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen {
  // declaration of friend membership
  friend void Window_mgr::clear(ScreenIndex);
  
public:
  // type alias for std::string::size_type
  typedef std::string::size_type pos;

  // CONSTRUCTORS
  Screen() = default;
  Screen(pos ht, pos wd): height(ht), width(wd),
			  contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c): height(ht), width(wd),
				  contents(ht * wd, c) {}
  // PUBLIC MEMBER FUNCTIONS
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);

  Screen &display(std::ostream &os){
    do_display(os);
    return *this;
  }
  
  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }
  
private:
  // PRIVATE MEMBERS
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

  // Helper function used in do_display
  void do_display(std::ostream &os) const {
    os << contents;
  }
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

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r*width + col] = ch;
  return *this;
}

// Definition of clear
void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the Screen we want to clear
  Screen &s = screens[i];
  // reset the contents of that Screen to all blanks
  s.contents = std::string(s.height * s.width, ' ');
}
