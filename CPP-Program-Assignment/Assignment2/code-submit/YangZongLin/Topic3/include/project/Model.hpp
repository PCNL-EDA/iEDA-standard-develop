/*
 * @Author: YangZongLin
 * @Date: 2021-07-31
 * @Description: Abstraction of a graph
 * @FilePath: /Topic3/include/project/Model.hpp
 * @copyright:
 */
#ifndef PROJECT_MODEL_HPP_
#define PROJECT_MODEL_HPP_

#include <algorithm>
#include <iostream>
#include <list>
#include <set>

#include "Map.hpp"
#include "Point.hpp"

namespace astar {
class Model {
 private:
  Map _a_map;
  std::set<Point> _open_list;
  std::list<Point> _close_list;
  Point* _start_point = nullptr;
  Point* _end_point = nullptr;
  Point _curr_point;
  Point* _neib_point = nullptr;

 public:
  Model() {}
  ~Model() {}

  void initMap(const int& rows, const int& columns);
  void initOpenList();
  void initCloseList();

  int getColumnsNum();
  int getRowsNum();
  std::list<Point>& getCloseList();
  Point& getCurrPoint();

  void addNodeToOPenList(const Point& point);
  void addNodeToCloseList(const Point& point);
  void addObstacle(const int& row, const int& column);

  void deleteFirstFromOpenList();

  bool findInCloseList(const Point& point);
  bool findInOpenList(const Point& point);

  void setCostForPoint(Point& point);
  void setCurrentPoint(const Point& point);
  void setEndPoint(const int& row, const int& column);
  void setStartPoint(const int& row, const int& column);

  bool canAddIntoOpenList(const int& i, const int& j);
  bool canThrough(const int& i, const int& j);
  void continueFindWay();
  int countNeedCost(const Point& curr, const Point& end);
  std::list<Point>& findBestWay();
  bool showTheWay();
  void visitNeighbor();
};

inline void Model::initMap(const int& rows, const int& columns) {
  _a_map.initMap(rows, columns);
}
inline void Model::initOpenList() { _open_list.clear(); }
inline void Model::initCloseList() { _close_list.clear(); }

inline int Model::getColumnsNum() { return _a_map.getColumnsRang(); }
inline int Model::getRowsNum() { return _a_map.getRowsRang(); }
inline std::list<Point>& Model::getCloseList() { return _close_list; }
inline Point& Model::getCurrPoint() { return _curr_point; }

inline void Model::addNodeToOPenList(const Point& point) {
  _open_list.insert(point);
}
inline void Model::addNodeToCloseList(const Point& point) {
  _close_list.push_back(point);
}
inline void Model::addObstacle(const int& row, const int& column) {
  _a_map.getPoint(row, column).set_obstacle_status(true);
}

inline void Model::deleteFirstFromOpenList() {
  _open_list.erase(_open_list.begin());
}

inline bool Model::findInCloseList(const Point& point) {
  std::list<Point>::iterator it =
      find(_close_list.begin(), _close_list.end(), point);
  return it != _close_list.end();
}
inline bool Model::findInOpenList(const Point& point) {
  std::set<Point>::iterator it =
      find(_open_list.begin(), _open_list.end(), point);
  return it != _open_list.end();
}

inline void Model::setCostForPoint(Point& point) {
  int increment = point.get_x() != getCurrPoint().get_x() &&
                          point.get_y() != getCurrPoint().get_y()
                      ? 144
                      : 100;
  point.set_have_cost(increment + getCurrPoint().get_have_cost());
  point.set_need_cost(countNeedCost(point, *_end_point));
  point.set_cost(point.get_have_cost() + point.get_need_cost());
}
inline void Model::setCurrentPoint(const Point& point) { _curr_point = point; }
inline void Model::setEndPoint(const int& row, const int& column) {
  _end_point = &(_a_map.getPoint(row, column));
}
inline void Model::setStartPoint(const int& row, const int& column) {
  _start_point = &(_a_map.getPoint(row, column));
  setCurrentPoint(*_start_point);
}

inline bool Model::canAddIntoOpenList(const int& i, const int& j) {
  return (_a_map.getPoint(i, j).get_obstacle_status() != true) &&
         (findInCloseList(_a_map.getPoint(i, j)) == false) &&
         (findInOpenList(_a_map.getPoint(i, j)) == false) &&
         (canThrough(i, j) == true);
}

inline bool Model::canThrough(const int& i, const int& j) {
  int curr_x = getCurrPoint().get_x();
  int curr_y = getCurrPoint().get_y();
  return getCurrPoint().get_obstacle_status() != 1 &&
         (_a_map.getPoint(curr_x, j).get_obstacle_status() != 1 ||
          _a_map.getPoint(i, curr_y).get_obstacle_status() != 1);
}

inline void Model::continueFindWay() {
  deleteFirstFromOpenList();
  addNodeToCloseList(getCurrPoint());
  visitNeighbor();
}

inline int Model::countNeedCost(const Point& curr, const Point& end) {
  int x = curr.get_x() > end.get_x() ? curr.get_x() - end.get_x()
                                     : end.get_x() - curr.get_x();
  int y = curr.get_y() > end.get_y() ? curr.get_y() - end.get_y()
                                     : end.get_y() - curr.get_y();
  return (x + y) * 100;
}
}  // namespace astar

#endif  // PROJECT_MODEL_HPP_
