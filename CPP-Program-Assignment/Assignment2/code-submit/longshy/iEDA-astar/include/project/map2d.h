/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the header file of map2d.
 * @FilePath: /a-star/include/map2d.h
 */

#pragma once
#include <functional>
#include <vector>

// location2d: represents a coordinate point on a map
struct location2d {
  int x, y;
  location2d(int x_ = -1, int y_ = -1) : x(x_), y(y_) {}
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
  using value_type = location2d;
  map2d(const std::vector<std::vector<char>>& rawmap,
        const std::vector<value_type>& move, const value_type& start,
        const value_type& end);
  ~map2d() {}

  void getAdjacentLocation(const value_type& curr,
                           std::vector<value_type>& rlt) const;
  value_type getStartLocation() const { return _m_start; }
  value_type getEndLocation() const { return _m_end; }
  char getElement(const value_type& curr) const {
    return _m_map[curr.y][curr.x];
  }
  int getRows() const { return _m_map.size(); }
  int getCols() const {
    return _m_map.empty() ? 0 : static_cast<int>(_m_map[0].size());
  }

 private:
  bool is_feaseable(const value_type& location) const;
  std::vector<std::vector<char>> _m_map;
  std::vector<value_type> _m_move;
  const value_type _m_start, _m_end;
};
