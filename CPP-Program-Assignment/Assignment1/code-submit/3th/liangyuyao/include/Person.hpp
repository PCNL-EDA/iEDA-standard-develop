/**
 * @file        Person.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __PERSON_HPP_
#define __PERSON_HPP_

#include <stdint.h>

#include <string>

namespace DROP_3th_ASSIGNMENT1 {

typedef uint32_t Person_ID;

/**
 * @brief
 * This class is related to people.txt
 * @exception
 */
class Person {
 public:
  // constructor
  Person() = default;
  Person(Person_ID pid, std::string name, uint32_t year)
      : _pid(pid), _name(name), _year(year) {}
  ~Person() = default;
  Person(const Person&) = default;

  // get
  const Person_ID getPid() const { return _pid; }
  const std::string getName() const { return _name; }
  const uint32_t getYear() const { return _year; }
  // set
  void setPid(Person_ID pid) { _pid = pid; }
  void setName(std::string name) { _name = name; }
  void setYear(uint32_t year) { _year = year; }

 private:
  Person_ID _pid;  // person id
  std::string _name;
  uint32_t _year;  // year of birth
};

}  // namespace DROP_3th_ASSIGNMENT1
#endif  // __PERSON_HPP_