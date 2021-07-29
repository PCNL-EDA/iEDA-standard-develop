#include "tmp.hpp"

#include <gtest/gtest.h>
#include<iostream>

/*bool InPath(const int &row, const int &col, const list<Node *> &path) {
  for (auto &p : path) {
    if (row == p->getX() && col == p->getY()) {
      return true;
    }
  }
  return false;
}
  */


/*TEST(TmpAddTest, CheckValues)
{
  ASSERT_EQ(tmp::add(1, 2), 3);
  EXPECT_TRUE(true);
}
*/
int main(int argc, char **argv)
{
  //::testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();
  //设置地图，0表示可以通过，1表示障碍
  vector<vector<int>>obstaclelist={ {0,0,0,0,1,1,1,1},
                              {0,0,0,0,0,1,1,1},
                              {1,1,0,1,1,0,0,0},
                              {1,0,0,0,0,0,0,0}};
	 //设置起始和终点
  Node start(0,0);
  Node end(3,7);									   
  Astar astar(obstaclelist);
 
 
 
  // A*算法找寻路径
  list<Node *> path = astar.getPath(start, end, false);
 
  // 打印结果
  for (Node*p : path) {
    cout << "(" << p->getX() << "," << p->getY() << ") ";
  }
  cout << "\n";
 
  /*for (int row = 0; row < obstaclelist.size(); ++row) {
    for (int col = 0; col < obstaclelist[0].size(); ++col) {
      if (InPath(row, col, path)) {
        if (obstaclelist[row][col] != 0) {
        cout << "e ";
        } else {
        cout << "* ";
        }
      } else {
        cout << obstaclelist[row][col] << " ";
      }
    }
    cout << "\n";
  }*/
    return 0;


}

