/*
 * @Author: YangZongLin
 * @Date: 2021-07-30
 * @Description: Abstraction of points in a graph
 * @FilePath: /Topic3/include/project/Point.hpp
 * @copyright:
 */

#ifndef PROJECT_POINT_HPP_
#define PROJECT_POINT_HPP_

namespace astar {
/**
 * @class Point
 * @brief This class is an abstraction of the lattices on the map
 */
class Point {
 public:
  Point() = default;
  ~Point() = default;

  void operator=(const Point& point) {
    _x = point._x;
    _y = point._y;
    _obstacle_status = point._obstacle_status;
    _have_cost = point._have_cost;
    _need_cost = point._need_cost;
    _cost = point._cost;
  }
  bool operator==(const Point& point) const {
    return (_x == point._x && _y == point._y);
  }
  bool operator<(const Point& point) const { return _cost < point._cost; }
  bool operator()(const Point& point) const { return _cost < point._cost; }

  int get_x() const { return _x; }
  int get_y() const { return _y; }
  bool get_obstacle_status() const { return _obstacle_status; }
  int get_have_cost() const { return _have_cost; }
  int get_need_cost() const { return _need_cost; }
  int get_cost() const { return _cost; }

  void set_x(const int& x) { _x = x; }
  void set_y(const int& y) { _y = y; }
  void set_obstacle_status(const bool& status) { _obstacle_status = status; }
  void set_have_cost(int cost) { _have_cost = cost; }
  void set_need_cost(int cost) { _need_cost = cost; }
  void set_cost(int cost) { _cost = cost; }

 private:
  int _x = 0;                    /**< Ordinate of the lattice */
  int _y = 0;                    /**< Abscissa of the lattice */
  bool _obstacle_status = false; /**< Are there any obstacles at this lattice */
  int _have_cost = 0; /**< Distance to go from the start point to the grid */
  int _need_cost =
      0;         /**< Estimate the distance to go from the grid to the end */
  int _cost = 0; /** Sum of _have_cost and _need_cost */
};
}  // namespace astar

#endif  // PROJECT_POINT_HPP_
