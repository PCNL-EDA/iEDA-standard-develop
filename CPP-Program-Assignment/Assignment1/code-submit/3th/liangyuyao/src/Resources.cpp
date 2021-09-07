/**
 * @file        Resources.cpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include "Resources.hpp"

#include <string.h>

/**
 * @brief       parse relationship.txt
 *
 * @param       graph save parsed data in the form of adjacency list
 * @exception
 */
void Resources::parseRelationshipTxt(DirectedGraph &graph) {
  const char *file_path = "../resources/relationship.txt\0";
  FILE *fp = fopen(file_path, "r");
  if (fp) {
    const uint16_t buff_szie = 128;
    char buff[buff_szie] = {0};
    AdjList adj_list;

    // resize adj_list
    assert(fgets(buff, sizeof(decltype(*buff)) * buff_szie, fp) != nullptr);
    Node_ID vertex_num = 0;  // count valid vertex
    for (auto *p = buff; *p; ++p) {
      switch (*p) {
        case '0':
        case '1':
          ++vertex_num;
          break;
      }
    }
    adj_list.resize(vertex_num);

    // build edges
    fseek(fp, 0, SEEK_SET);
    Node_ID v_in = 0;  // vertex in
    Node_ID v_out;     // vertex out
    while (!feof(fp)) {
      // ensure adj_list valid
      assert(v_in <= vertex_num - 1);

      adj_list[v_in].resize(0);
      memset(buff, 0, buff_szie);
      assert(fgets(buff, sizeof(decltype(*buff)) * buff_szie, fp) != nullptr);

      // row data
      bool row_valid = false;
      v_out = 0;
      for (auto *p_src = buff; *p_src; ++p_src) {
        switch (*p_src) {
          // filter ' ' and '\n'
          case '0':
            row_valid |= true;
            ++v_out;
            break;
          case '1':
            row_valid |= true;
            adj_list[v_in].push_back(v_out++);
            break;
        }
      }

      // ensure adj_list valid
      assert(adj_list[v_in].size() <= vertex_num);
      // row data may contain '\n'
      v_in += row_valid ? 1 : 0;

    }  // end while (!feof(fp))

    fclose(fp);
    graph.setAdjList(adj_list);
  } else {
    printf("path error: %s\n", file_path);
  }  // end if (fp)
}

/**
 * @brief       parse people.txt
 *
 * @param       people save parsed data in vector
 * @exception
 */
void Resources::parsePeopleTxt(std::vector<Person> &people) {
  const char *file_path = "../resources/people.txt\0";
  FILE *fp = fopen(file_path, "r");
  if (fp) {
    const uint16_t buff_szie = 32;
    char name[buff_szie] = {0};
    Person_ID pid = 0;
    uint32_t year;

    while (!feof(fp)) {
      memset(name, 0, buff_szie);
      assert(fscanf(fp, "%u %s %u", &pid, name, &year) != 0);
      Person p(pid, name, year);
      people.push_back(p);
    }

    fclose(fp);
  } else {
    printf("path error: %s\n", file_path);
  }  // end if (fp)
}