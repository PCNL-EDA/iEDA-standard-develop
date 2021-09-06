/**
 * @file person.h
 * @author congx
 * @brief A person class contain id, name and birthday.
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021 PCL
 * 
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_PERSON_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_PERSON_H_

#include <fstream>
#include <string>

/**
 * @brief A person class that contain some member.
 *
 * The person class overloads the input/output operators
 */
class Person {
  friend std::istream& operator>>(std::istream& is, Person& person);
  friend std::ostream& operator<<(std::ostream& os, Person& Person);

 public:
  Person() = default;
  Person(int id, const std::string& name, const std::string& birthday)
      : _id(id), _name(name), _birthday(birthday) {}

  ~Person() = default;

  /**
   * @brief Get the nubmer of object
   *
   * @return const int
   */
  const int get_id() const { return _id; }

  /**
   * @brief Get the name of object
   *
   * @return const std::string&
   */
  const std::string& get_name() const { return _name; }

  /**
   * @brief Get the birthday of object
   *
   * @return const std::string&
   */
  const std::string& get_birthday() const { return _birthday; }

  /**
   * @brief Set the id of object
   *
   * @param id  the number of the object
   */
  void set_id(int id);

  /**
   * @brief Set the id of object
   *
   * @param id  the number of the object
   */
  void set_name(const std::string& name);

  /**
   * @brief Set the id of object
   *
   * @param id  the number of the object
   */
  void set_birthday(const std::string& birthday);

 private:
  int _id;
  std::string _name;
  std::string _birthday;  ///< date of birth
};

/**
 * @brief Class to overload the input operator
 * 
 * @param is input stream object
 * @param person The class of the overloaded operator
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Person& person);

/**
 * @brief Class to overload the output operator
 * 
 * @param is output stream object
 * @param person The class of the overloaded operator
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, Person& person);

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_PERSON_H_
