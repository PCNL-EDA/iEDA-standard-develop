/*
 * @Author: YangZongLin
 * @Date: 2021-07-31
 * @Description: Definition of member function of class model
 * @FilePath: /Topic3/src/Model.cpp
 * @copyright:
 */
#include "../include/project/Model.hpp"

namespace astar {
/** @brief Calling this function will cause the best path to be stored in the
 *         Closelist
 *  @return Returns the Closelist containing the results
 */
std::list<Point>& Model::findBestWay() {
  initOpenList();                    // Clear OpenList
  initCloseList();                   // Clear OpenList
  addNodeToOpenList(*_start_point);  // Put the starting point into OpenList
  while (_open_list.empty() != 1) {
    setCurrentPoint(*_open_list.begin());  // Take the first element in openlist
                                           // as the current point
    if (_curr_point == *_end_point)        // If reached the end point
      return getCloseList();
    else
      continueFindWay();  // Didn't reached the end point,Continue find way
  }
  _close_list.clear();    // Can't find a way reach the end point
  return getCloseList();  // Return the empty list
}

/** @brief Print out the best path stored in openlist in a certain format
 *  @return Returns whether the results are stored in the list
 */
bool Model::showTheWay() {
  if (_close_list.empty() == true) {
    std::cout << "There is no way to the end！！！" << std::endl;
    return false;
  }
  for (std::list<Point>::iterator it = _close_list.begin();
       it != _close_list.end(); it++) {
    std::cout << "(" << (*it).get_x() << "," << (*it).get_y() << ") -> ";
  }
  std::cout << "(" << (*_end_point).get_x() << "," << (*_end_point).get_y()
            << ")" << std::endl;
  return true;
}

/** @brief Filter the points around the current point and add them to Openlist
 */
void Model::visitNeighbor() {
  int curr_x = getCurrPoint().get_x();
  int curr_y = getCurrPoint().get_y();
  // Determine the ordinate range when traversing neighbor points
  int x_rang_min = curr_x - 1 > 0 ? curr_x - 1 : 0;
  int x_rang_max =
      curr_x + 1 < getRowsNum() - 1 ? curr_x + 1 : getRowsNum() - 1;
  // Determine the abscissa range when traversing neighbor points
  int y_rang_min = curr_y - 1 > 0 ? curr_y - 1 : 0;
  int y_rang_max =
      curr_y + 1 < getColumnsNum() - 1 ? curr_y + 1 : getColumnsNum() - 1;
  for (int i = x_rang_min; i <= x_rang_max; i++) {
    for (int j = y_rang_min; j <= y_rang_max; j++)
      if (canAddIntoOpenList(i, j) == true &&
          (curr_x != i || curr_y != j)) {  // If the neighbor points meet the
                                           // conditions for joining Openlist
        setCostForPoint(
            _a_map.getPoint(i, j));  // Estimate the length of the whole path
                                     // after adding this point
        addNodeToOpenList(
            _a_map.getPoint(i, j));  // Add this point into OpenList
      }
  }
}
}  // namespace astar
