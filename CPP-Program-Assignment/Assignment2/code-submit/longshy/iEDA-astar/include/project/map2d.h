/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the header file of map2d.
 * @FilePath: /IEDA-ASTAR/include/project/map2d.h
 */

#pragma once
#include <functional>
#include <vector>

// location2d: represents a coordinate point on a map
struct location2d {
  int x, y;
  location2d(int a = -1, int b = -1) : x(a), y(b) {}
  location2d operator+(const location2d& rhs) const {
    return location2d(x + rhs.x, y + rhs.y);
  }
  bool operator==(const location2d& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  bool operator<(const location2d& rhs) const {
    return x == rhs.x ? y < rhs.y : x < rhs.x;
  }
};

// map2d:represents a map
class map2d {
 public:
  map2d(const std::vector<std::vector<char>>& rawmap,
        const std::vector<location2d>& move, const location2d& start,
        const location2d& end);
  ~map2d() {}

  void getAdjacentLocation(const location2d& curr,
                           std::vector<location2d>& rlt) const;
  location2d getStartLocation() const { return _start; }
  location2d getEndLocation() const { return _end; }
  char getElement(const location2d& curr) const {
    return _map[static_cast<int>(curr.y)][static_cast<int>(curr.x)];
  }
  int getRows() const { return static_cast<int>(_map.size()); }
  int getCols() const {
    return _map.empty() ? 0 : static_cast<int>(_map[0].size());
  }

 private:
  bool isFeaseable(const location2d& location) const;
  std::vector<std::vector<char>> _map;
  std::vector<location2d> _move;
  const location2d _start, _end;
};
