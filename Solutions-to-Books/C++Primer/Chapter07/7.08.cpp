// Exercise 7.9
// Add operations to read and print Person objects
// to the code you wrote for the exercises in
// Section 7.1.2 (p.260)
// Xiaoyan Wang 3/7/2016

// Mostly copied from 7.5.cpp
#include <string>
#include <iostream>

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

std::istream& read(std::istream& is, Person& per) {
  is >> per.name >> per.address;
  return istream;
}

std::ostream& print(std::ostream& os, const Person& per) {
  os << per.name << ' ' << per.address;
  return ostream;
}
