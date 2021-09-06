// Copyright 2021 PCL.
// Author: congxian

#include "person.h"

void Person::set_id(int id) { this->_id = id; }

void Person::set_name(const std::string& name) { this->_name = name; }

void Person::set_birthday(const std::string& birthday) {
  this->_birthday = birthday;
}

std::istream& operator>>(std::istream& is, Person& person) {
  is >> person._id >> person._name >> person._birthday;
  return is;
}

std::ostream& operator<<(std::ostream& os, Person& person) {
  os << person._id << " " << person._name << " " << person._birthday;
  return os;
}
