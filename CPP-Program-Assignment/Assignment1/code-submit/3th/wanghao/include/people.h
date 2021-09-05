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

  void     printAll() const;
  unsigned how_many_people() const;

  void read_file(FILE *);
  void printNameById(unsigned);

  People(People &)  = delete;
  People(People &&) = delete;

 private:
  std::map<unsigned, const char *> *_people;
};

#endif