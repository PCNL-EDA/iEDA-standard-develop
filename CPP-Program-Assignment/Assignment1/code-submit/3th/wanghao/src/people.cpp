/**
 * @file          people.cpp
 * @brief         implementation of Class People
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <people.h>
#define NAME_BUFFER 128

/**
 * @brief read people's data from file fp
 * @param fp
 */
void People::read_file(FILE *fp) {
  // get number of people
  unsigned people_size;
  int      discard;
  discard = fscanf(fp, "%u\n", &people_size);

  // read infomation, discard person_birthday
  unsigned person_id, person_birthday;

  while (people_size--) {
    char *person_name = new char[NAME_BUFFER];
    discard           = fscanf(fp, "%u %s %u\n", &person_id, person_name, &person_birthday);
    _people->insert(std::make_pair(person_id, person_name));
  }
}

/**
 * @brief Construct a new People:: People object
 */
People::People() { _people = new std::map<unsigned, const char *>; }

/**
 * @brief Destroy the People:: People object
 */
People::~People() {
  if (_people != nullptr) {
    for (auto &person : *_people) {
      delete person.second;
    }

    delete _people;
  }
}

/**
 * @brief print people's infomation
 */
void People::printAll() const {
  printf(">>> print id and name for each one of registed people\n");
  for (const auto &person : *_people) {
    printf("id:%u\t%s\n", person.first, person.second);
  }
  putchar('\n');
}