// Exercise 7.15
// Add appropriate constructors to your Person class
// Xiaoyan Wang 3/7/2016

// Mostly copied from 7.9.cpp
#include <string>
#include <iostream>

struct Person;
std::istream& read(std::istream& is, Person& per);
std::ostream& print(std::ostream& os, const Person& per);

struct Person {
  // NEW: constructors
  Person() = default;
  Person(std::string n): name(n) {}
  Person(const std::string& n, const std::string& addr):
    name(n), address(addr) {}
  Person(std::istream& is) {
    read(is, *this);
  }
  
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
