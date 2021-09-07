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

class People {
 public:
  People();
  ~People();
  void operator=(const People &) = delete;

  inline void     printNameById(unsigned) const;
  inline unsigned how_many_people() const;

  void printAll() const;
  void read_file(FILE *);

  People(People &)  = delete;
  People(People &&) = delete;

 private:
  std::map<unsigned, const char *> *_people;
};

// inline function:

/**
 * @brief print name by id obviously
 * @param id
 */
void People::printNameById(unsigned id) const {
  auto person = _people->find(id);
  if (person != _people->end()) {
    printf("%u %s", id, person->second);
  }
}

/**
 * @brief return how many people's infomation are stored
 * @return unsigned
 */
unsigned People::how_many_people() const { return _people->size(); }

#endif