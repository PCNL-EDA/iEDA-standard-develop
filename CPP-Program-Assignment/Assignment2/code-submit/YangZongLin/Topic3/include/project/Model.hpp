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
/**
 * @class Model
 * @brief This class is used to process the data of map and points
 */
class Model {
 public:
  Model() = default;
  ~Model() = default;

  std::list<Point>& findBestWay();
  bool showTheWay();
  void visitNeighbor();

  void initMap(const int& rows, const int& columns) {
    _a_map.initMap(rows, columns);
  }
  void initOpenList() { _open_list.clear(); }
  void initCloseList() { _close_list.clear(); }

  /** @brief Gets the total number of columns in the graph
   *  @return Returns the total number of columns in the graph
   */
  int getColumnsNum() { return _a_map.getColumnsRang(); }
  /** @brief Gets the total number of rows in the graph
   *  @return Returns the total number of rows in the graph
   */
  int getRowsNum() { return _a_map.getRowsRang(); }
  std::list<Point>& getCloseList() { return _close_list; }
  Point& getCurrPoint() { return _curr_point; }

  void addNodeToOpenList(const Point& point) { _open_list.insert(point); }
  void addNodeToCloseList(const Point& point) { _close_list.push_back(point); }
  void addObstacle(const int& row, const int& column) {
    _a_map.getPoint(row, column).set_obstacle_status(true);
  }

  /** @brief Delete the first element of OpenList
   */
  void deleteFirstFromOpenList() { _open_list.erase(_open_list.begin()); }

  /** @brief Determine whether the input points are also stored in Closelist
   *  @return If the point be found in the list,return true,otherwise,return
   * false
   */
  bool findInCloseList(const Point& point) {
    std::list<Point>::iterator it =
        find(_close_list.begin(), _close_list.end(), point);
    return it != _close_list.end();
  }
  /** @brief Determine whether the input points are also stored in Openlist
   *  @return If the point be found in the list,return true,otherwise,return
   * false
   */
  bool findInOpenList(const Point& point) {
    std::set<Point>::iterator it =
        find(_open_list.begin(), _open_list.end(), point);
    return it != _open_list.end();
  }
  /** @brief Estimate the length of the whole path after adding this point
   */
  void setCostForPoint(Point& point) {
    int increment =
        point.get_x() != getCurrPoint().get_x() &&
                point.get_y() != getCurrPoint().get_y()
            ? 144: 100;  // If this point is in the same row or column as the
                         // current point, set the distance increment to 100,
                         // otherwise 144
    point.set_have_cost(
        increment +
        getCurrPoint()
            .get_have_cost());  // This point' _have_Cost is the cost of the
                                // current point' _have_Cost plus increment
    point.set_need_cost(countNeedCost(
        point, *_end_point));  // This point' _need_Cost is the Manhattan
                               // distance between this point and the end point
    point.set_cost(point.get_have_cost() +
                   point.get_need_cost());  // This point' cost is the
                                            // _have_cost add _need_cost
  }
  void setCurrentPoint(const Point& point) { _curr_point = point; }
  void setEndPoint(const int& row, const int& column) {
    _end_point = &(_a_map.getPoint(row, column));
  }
  void setStartPoint(const int& row, const int& column) {
    _start_point = &(_a_map.getPoint(row, column));
    setCurrentPoint(*_start_point);
  }

  /** @brief Judge whether this point meets the conditions for adding Openlist
   *  @return If the condition is met, it returns true; otherwise, it returns
   * false
   */
  bool canAddIntoOpenList(const int& i, const int& j) {
    return (_a_map.getPoint(i, j).get_obstacle_status() !=
            true) &&  // Condition 1: there is no obstacle at this point
           (findInCloseList(_a_map.getPoint(i, j)) ==
            false) &&  // Condition 2: the point is not in the Closelist
           (findInOpenList(_a_map.getPoint(i, j)) ==
            false) &&  // Condition 3: the point is not in openlist
           (canThrough(i, j) == true);  // Condition 4: can reach this point
                                        // directly from the current point
  }
  /** @brief Determine whether you can reach this point directly from the
   * current point
   *  @return If able to reach, return true; otherwise, return false
   */
  bool canThrough(const int& i, const int& j) {
    int curr_x = getCurrPoint().get_x();
    int curr_y = getCurrPoint().get_y();
    return getCurrPoint().get_obstacle_status() != 1 &&
           (_a_map.getPoint(curr_x, j).get_obstacle_status() != 1 ||
            _a_map.getPoint(i, curr_y).get_obstacle_status() != 1);
  }
  /** @brief Add the current point from the to be selected list to the confirmed
   * list, and circle around it to find the next point to be added to the path
   */
  void continueFindWay() {
    deleteFirstFromOpenList();
    addNodeToCloseList(getCurrPoint());
    visitNeighbor();
  }

  /** @brief Calculate the Manhattan distance from this point to the end point
   *  @return Returns the absolute value of the difference between the abscissa
   * and ordinate of two points and multiplies it by 100
   */
  int countNeedCost(const Point& curr, const Point& end) {
    int x = curr.get_x() > end.get_x() ? curr.get_x() - end.get_x()
                                       : end.get_x() - curr.get_x();
    int y = curr.get_y() > end.get_y() ? curr.get_y() - end.get_y()
                                       : end.get_y() - curr.get_y();
    return (x + y) * 100;
  }

 private:
  Map _a_map;
  std::set<Point> _open_list;   /**< Store candidate points */
  std::list<Point> _close_list; /**< Store selected points */
  Point* _start_point = nullptr;
  Point* _end_point = nullptr;
  Point _curr_point; /**< Stores the point currently being accessed */
};
}  // namespace astar

#endif  // PROJECT_MODEL_HPP_
