/**
 * @brief       store integrity map
 * @author      liujikang
 * @date        2021-07-31
 * @copyright   liujikang
 * 
 */

#ifndef CODE_SUBMIT_LIUJIKANG_INCLUDE_GRIDMAP_H_
#define CODE_SUBMIT_LIUJIKANG_INCLUDE_GRIDMAP_H_

namespace astar {

template<typename T>
class GridMap {
 public:
  GridMap() {}
  GridMap(int row, int col) : _row_num(row), _col_num(col) { initArrNode(); }
  ~GridMap() { deleteArrNode(); }
  ///< getter
  int get_row_num() const { return _row_num; }
  int get_col_num() const { return _col_num; }
  T** get_arrNode() const { return _arrNode; }
  T* operator[](const int i) { return _arrNode[i]; }

  ///< function
  void initArrNode(int row_num = 0, int col_num = 0);
  void deleteArrNode();
 private:
  int _row_num = 0;
  int _col_num = 0;
  T** _arrNode = nullptr;
};


template <typename T>
inline void GridMap<T>::initArrNode(int row_num, int col_num) {
  _row_num = row_num;
  _col_num = col_num;
  deleteArrNode();
  _arrNode = new T*[_row_num];
  _arrNode[0] = new T[_row_num * _col_num];
  for (int i = 1; i < _row_num; i++) {
      _arrNode[i] = _arrNode[i - 1] + _col_num;
  }
}

template <typename T>
inline void GridMap<T>::deleteArrNode() {
  delete[] _arrNode;
  _arrNode = nullptr;
}

}  // namespace astar

#endif  // CODE_SUBMIT_LIUJIKANG_INCLUDE_GRIDMAP_H_
