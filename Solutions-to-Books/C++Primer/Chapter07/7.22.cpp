// Exercise 7.22
// Update your Person class to hide its implementation.
// Xiaoyan Wang 3/16/2016

// Mostly copied from 7.15.cpp
#include <string>
#include <iostream>

class Person;
std::istream& read(std::istream& is, Person& per);
std::ostream& print(std::ostream& os, const Person& per);

class Person {
  // NEW: declaration of friend functions
  friend std::istream& read(std::istream& is, Person& per);
  friend std::ostream& print(std::ostream& os, const Person& per);

public:
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

private:
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
