/**
 * @file Coordinate.h
 * @author lvyaxing
 * @brief 
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _INCLUDE_COORDINATE_H_
#define _INCLUDE_COORDINATE_H_
namespace MyAStar {
  /** 
   * @class Coordinate
   * @brief Coordinates of obstacle points
   */
  class Coordinate
  {
    public:

    Coordinate(int x, int y) : _x(x), _y(y) {}
    ~Coordinate() {}
    int get_x() const { return _x; }
    int get_y() const { return _y; }

    private:

    int _x = 0;
    int _y = 0;
  };
}  // namespace MyAStar
#endif  // _INCLUDE_COORDINATE_H_
