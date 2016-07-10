// Exercise 7.5
// Provide operations in your Person class
// to return the name and address.
// Xiaoyan Wang 3/7/2016
#include <string>

struct Person {
  std::string getName() const {
    return name;
  }

  std::string getAddress() const {
    return address;
  }
  
  std::string name;
  std::string address;
};
