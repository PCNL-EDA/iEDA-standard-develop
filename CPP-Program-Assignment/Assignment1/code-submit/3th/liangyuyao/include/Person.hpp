/**
 * @file        Person.hpp
 * @brief       
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include <stdint.h>
#include <string>

#ifndef __PERSON_HPP_
#define __PERSON_HPP_

typedef uint32_t Person_ID;

/**
 * @brief       
 * This class is related to people.txt
 * @exception   
 */
class Person
{
    private:
        Person_ID _pid;     //person id
        std::string _name;  
        uint32_t _year;  // year of birth
    public:
        // constructor
        Person() = default;
        Person(Person_ID, std::string, uint32_t);
        ~Person() = default;
        // get
        const Person_ID getPid() const;
        const std::string getName() const;
        const uint32_t getYear() const;
        // set
        Person& setPid(Person_ID);
        Person& setName(std::string);
        Person& setYear(uint32_t);
        // copy
        Person(const Person&) = default;
};

inline Person::Person(Person_ID pid, std::string name, uint32_t year)
                              :_pid(pid),       _name(name),   _year(year) {}
inline const Person_ID Person::getPid() const { return _pid; }
inline const std::string Person::getName() const { return _name; }
inline const uint32_t Person::getYear() const { return _year; }
inline Person& Person::setPid(Person_ID pid) { _pid = pid; return *this; }
inline Person& Person::setName(std::string name) { _name = name; return *this; }
inline Person& Person::setYear(uint32_t year) { _year = year; return *this; }



#endif // __PERSON_HPP_