/**
 * @file graph.h
 * @author congx
 * @brief This is a priority queue adapter.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PRIORITY_QUEUE_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PRIORITY_QUEUE_H_

#include <queue>
#include <utility>

namespace pather{

template <typename T, typename priority_t>
class PriorityQueue {
  typedef std::pair<priority_t, T> PQElement;

 public:
  bool empty() const { return elements.empty(); }
  void push(T item, priority_t priority) { elements.emplace(priority, item); }
  void pop() { elements.pop(); }
  T top() const { return elements.top().second; }

 private:
  std::priority_queue<PQElement, std::vector<PQElement>,
                      std::greater<PQElement>>
      elements;
};

} // astar
#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PRIORITY_QUEUE_H_
