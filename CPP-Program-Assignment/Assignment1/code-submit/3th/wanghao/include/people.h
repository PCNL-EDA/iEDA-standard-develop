/**
 * @file          people.h
 * @brief         Class People stores one's id and name
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef PERSON_H_
#define PERSON_H_
#include <map>

#define NAME_BUFFER 128

namespace Assignment1{
/**
 * @brief
 *
 * Class People stores everyone's id and name
 * you can print each one of people's infomation
 *
 */
class People {
 public:
  People() {
    _people = new std::map<unsigned, const char *>; 
  }
  People(People &)  = delete;
  People(People &&) = delete;
  ~People() {
    for (auto &person : *_people) {
      delete person.second;
    }
    delete _people;
  }
  void operator=(const People &) = delete;

  // get
  inline unsigned how_many_people() const {
    return _people->size();
  }

  // set
  void read_file(FILE *);

  void printAll() const;
  inline void printNameById(unsigned id) const {
    auto person = _people->find(id);
    if (person != _people->end()) {
      printf("%u %s", id, person->second);
    }
  }

 private:
  std::map<unsigned, const char *> *_people;
};

} // namespace Assignment1
#endif