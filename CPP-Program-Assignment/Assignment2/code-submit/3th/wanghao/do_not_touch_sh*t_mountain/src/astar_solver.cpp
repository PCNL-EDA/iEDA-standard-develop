#include "astar_solver.h"
#include <vector>
using std::vector;

namespace Assignment2 {
void AstarSolver::import_grid_map_from_file(const char *file_grid_map) {
  _data.import_obstacles_from_file(file_grid_map);
}

int AstarSolver::runSolver() {
  // 数据：
  // open  列表: 所有被考虑来寻找最短路径的格子
  // close 列表: 一个记录下不会再被考虑的格子
  // G(x): 从start到x的cost
  // H(x): 从x到end的预计cost
  // F(x): 走x点的全程cost = G+H

  /*
   * 清空 ret_path，open，close

   * start 合法吗？ set起始点，将start放入open，计算F
   * end 合法吗？ set终点
   *
   * do{
   *  从open中选出F最低点N 删除
   *  if（N是终点）{返回路径}
   *  N放入close
   *  if （N周围不在open中的点&&可达&&不在close）
   *    设置前驱为N,放入open,计算F
   *  else （N周围在open中的点&&可达&&不在close）
   *    计算此点的G=N'G+ N~此点距离，若新G小于当前G，设置前驱为N
   * }while(open是否为空)
   *
   */
  clearResultVector();
  clearOpenList();
  clearCloseList();

  if (initStartPoint() && initEndPoint()) {
    while (!isOpenListEmpty()) {
      popLowestFCostFromOpenList();  // pop to "current" node

      if (isCurrentDestination()) {
        return saveAstarPath();
      }

      pushCurrent2CloseList();
      pushNeighbor2OpenList();
    }
  }

  return saveNoPath();
}

void AstarSolver::displaySolverName() const {}
void AstarSolver::displayPorblemToBeSolved() const {}
void AstarSolver::displayResults() const {}
void AstarSolver::displayExecTimeMS() const {}

}  // namespace Assignment2