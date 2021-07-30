/**@file      astart.h
 * @brief     defined a namespace named Astart, in which including all declarations of functions locating in tmp.cpp.
 * @author    liujikang
 * @date      2021/07/28
 * @version   1.0.0
 * @copyright liujikang
 */ 
#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_INCLUDE_PROJECT_ASTART_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_INCLUDE_PROJECT_ASTART_H_

#include <vector>

/**
 * @namespace   Astart
 * @brief       declear a namespace for implement of Astart.\n
 *              including class Node and many declarations.     
 */
namespace Astart {
  /**
   * @name        mapArr
   * @brief       store map in array
   * @details     when A-START algorithm choose a node of map, set this node matched char as "*".
   */ 
  char mapArr[4][8] = {
      'S', '-', '-', '-', 'X', 'X', 'X', 'X',
      '-', '-', '-', '-', '-', 'X', 'X', 'X',
      'X', 'X', '-', 'X', 'X', '-', '-', '-',
      'X', '-', '-', '-', '-', '-', '-', 'E'
  };


  int gColMapArr = sizeof(mapArr[0]) / sizeof(mapArr[0][0]);  //< 一维数组的长度
  int gRowMapArr = sizeof(mapArr) / sizeof(mapArr[0]);  ///< 一维数组的个数


  /**
   * @class     Node
   * @brief     a Node instance stores all kinds information needed by Astart algorithm,\n
   *            including the Node' index in the mapArr and cost variables such as g,h,f, \n
   *            and the pointer variable parent designed to find the shortest path.
  */
  class Node{
   public:
    Node (int x, int y) { this->_astart_x = x; this->_astart_y = y;}
   public:
    int _astart_x, _astart_y;   ///<此节点对应的mapArr数组的下标<x,y>
    int _astart_g;              ///<起始点到当前节点路径长度/cost
    int _astart_h;              ///<当前节点到终点的路径长度h_cost，即启明函数的值
    int _astart_f;              ///<f = g + h
    Node *parent;
  };

  std::vector<Node *> openList; ///<将当前点紧邻的八个方向点Node
  std::vector<Node *> closeList; ///<将障碍点和已在路径上的点放置在close列表中


  void initMapArr(Node * &start, Node * &endNode);
  void printMap();
  void printPath (Node * node);
  bool isContain(std::vector<Node *> *v, int x, int y);
  int funcH(Node *node, Node *end);
  void modifyNode(int x, int y, Node * cur_node, Node *end);
  void releaseNode(Node* n);
  bool compare(Node* n1, Node* n2);
  bool searchPath(Node *start, Node *end);

  /**
   * @fn          init_mapArr
   * @details     create the instances startNode,endNode in the heap, assign node information for start and end Node of instances.
   * @param[in]   start       a cite to Node *, save the info of start node of shortest path.
   * @param[in]   endNode     a cite to Node *, save the info of end node of shortest path.
   * @return      None        return void
   * @see         function main will call this function     
   * 
   */  
  inline void initMapArr(Node * &start, Node * &endNode) {
    start = new Node(0, 0);
    endNode = new Node(3, 7);
  }


  /**
   * @fn          print_map
   * @brief       print the mapArr array, show the origin map in the first and the shortest path in the mapArr.
   * @return      none
   * @see         function main will call this function twice to show the difference.    
   */ 
  inline void printMap () {
      for (int i = 0; i < gRowMapArr; i++) {
          for (int j = 0; j < gColMapArr; j++)
              std::cout << mapArr[i][j] << " ";
          std::cout << std::endl;
      }
  }


  /**
   * @fn          isContain
   * @brief       where the node elemnt is contained in this vector container v.
   * @param[in]   v   vector container is checked.
   * @param[in]   x   the row index of node element.
   * @param[in]   y   the col index of node element.
   * @return      type bool 
   * @see         function modify_node calls this function.
   */ 
  inline bool isContain(std::vector<Node *> *v, int x, int y) {
      for (int i = 0; i < v->size(); i++)
          if ( v->at(i)->_astart_x == x && v->at(i)->_astart_y == y )
              return true;
      return false;
  }

  
    /**
   * @fn          func_h
   * @brief       valuate the cost between chosen node and end node.
   * @param       node    param node assigned the pointer of chosen node.
   * @param       end     param end assigned the pointer of end node of path, valuate the cost.
   * @return      the cost value of between chosen node and end.
   * @see         function modify_node.
   */ 
  inline int funcH(Node *node, Node *end) {
      return abs(end->_astart_x - node->_astart_x) + abs(end->_astart_y - node->_astart_y);
  }

  /**
   * @fn          releaseNode
   * @brief       using recurison algorithm release all created heap instances.
   * @param[in]   n    begin node of recurison operator.
   * @return      Node
   * @see         function search_path calls this function
   * 
   */ 
  inline void releaseNode(Node* n) {     
      if (n->parent)
          Astart::releaseNode(n->parent);
      delete n;
  }

  
  /**
   * @fn          compare
   * @brief       define the rules of sort for template vector
   * @param[in]   n1  compare with n2
   * @param[in]   m2  compare with n1
   * @return      return type bool
   * @see         function vector instance's sort
   */ 
  inline bool compare(Node* n1, Node* n2) {//vector对象的sort函数降序排序
      return n1->_astart_f < n2->_astart_f;
  }

}


#endif