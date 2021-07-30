/**
 * @file     tmp.cpp
 * @brief    source code implement astart algorithm.    
 * @details  this file includes all definitions of function decleared in tmp.hpp and astart.h.
 * @author   liujikang
 * @date     2021/07/28
 * @version  1.0.0
 * @note     all the definition of functions located in this project should define in this file. 
 * @copyright liujikang
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "./include/project/astart.h"

/**
 * @fn          print_map
 * @brief       print the mapArr array, show the origin map in the first and the shortest path in the mapArr.
 * @return      none
 * @see         function main will call this function twice to show the difference.    
 */ 
void printMap() {
    for (int i = 0; i < Astart::gRowMapArr; i++) {
          for (int j = 0; j < Astart::gColMapArr; j++)
              std::cout << Astart::mapArr[i][j] << " ";
          std::cout << std::endl;
    }
}

/**
 * @fn          modify_node
 * @details     modify the attribute value of exists Node instance, \n
 *              or if the node don't exist and meet all conditions, new a Node instance.
 * @param[in]   x   the row index of node element.
 * @param[in]   y   the col index of node element.
 * @param[in]   cur_node    as the patent node, if sub node don't exist,\n 
 *                          new node'attribute g is assigined cur_node->g.
 * @return      Node
 * @see         function search_path will calls this function
 * @see         function isContain is called   
 * 
 */ 
void Astart::modifyNode(int x, int y, Node * cur_node, Node *end) {
    if (mapArr[x][y] == 'X')    ///< 要遍历的节点是障碍物
        return;
    ///< 要访问的节点是已包含在路径中
    if (Astart::isContain(&closeList, x, y) )
        return;
    if ( !Astart::isContain(&openList, x, y) ) {
    ///< 创建新结点并赋值,还没被添加到openList队列中时
        Node *n = new Node(x, y);
        n->_astart_g = cur_node->_astart_g + 1;
        n->_astart_h = funcH(n, end);
        n->_astart_f = n->_astart_g + n->_astart_h;
        n->parent = cur_node;
    ///< 将新结点加入列表
        Astart::openList.push_back(n);
    }
}


/**
 * @fn          search_path
 * @brief       find the existed shortest path by implementing the A-START algorithm
 * @param[in]   start   the begin node element of path
 * @param[in]   end     the end node element of path
 * @return      type bool
 * @see         function main will call this function.
 * @see         function func_h,modify_node,print_path,compare,sort,releaseNode
 */ 
bool Astart::searchPath(Node *start, Node *end) {
    if (mapArr[start->_astart_x][start->_astart_y] == 'X' ||
        mapArr[end->_astart_x][end->_astart_y] == 'X')
        return -1;
    ///< 为起始节点赋值
    start->_astart_g = 0;
    start->_astart_h = Astart::funcH(start, end);
    start->_astart_f = start->_astart_g + start->_astart_h;
    start->parent = NULL;
    ///< 将起始节点加入到列表中
    Astart::openList.push_back(start);

    Node * cur_node = NULL;  ///< 保存当前访问的节点

    bool find_path = false;  ///< 收否找到一条路径

    int x, y;
    while (!Astart::openList.empty()) {
        cur_node = openList[0];  ///< openList的对首元素就是路径要访问的节点。

        if (cur_node->_astart_x == end->_astart_x &&
            cur_node->_astart_y == end->_astart_y) {    ///< 当前节点是否为终点
            find_path = true;
            break;
        }
        x = cur_node->_astart_x;
        y = cur_node->_astart_y;
        ///< 路径节点不是起始和终点时，置为【*】
        if (mapArr[x][y] != 'S' && mapArr[x][y] != 'E')
            mapArr[x][y] = '*';

        ///< 访问当前节点的周围的八个节点
        if ( (x + 1) <= gRowMapArr - 1 )  ///< 当前节点的右边节点
            Astart::modifyNode(x+1, y, cur_node, end);
        if ( x - 1 >= 0 )                 ///< 当前节点的左边节点
            Astart::modifyNode(x-1, y, cur_node, end);
        if ( y - 1 >= 0 )                 ///< 当前节点的上边节点
            Astart::modifyNode(x, y-1, cur_node, end);
        if ( y + 1 <= gColMapArr -1 )     ///< 当前节点的下边节点
            Astart::modifyNode(x, y+1, cur_node, end);
        ///< 当前节点的右下节点/左下节点/左上节点
        if ( x + 1 <= gRowMapArr - 1 && y + 1 <= gColMapArr -1 )
            Astart::modifyNode(x + 1, y + 1, cur_node, end);
        if ( x + 1 <= gRowMapArr && y - 1 >= 0 )
            Astart::modifyNode(x + 1, y - 1, cur_node, end);
        if ( x - 1 >= 0 && y + 1 <= gColMapArr -1 )
            Astart::modifyNode(x - 1, y + 1, cur_node, end);
        if ( x - 1 >= 0 && y - 1 >= 0 )
            Astart::modifyNode(x - 1, y - 1, cur_node, end);


        ///< 将当前节点的八个方向节点访问一遍，从openList删除，加入closeList中
        closeList.push_back(cur_node);
        openList.erase(openList.begin());
        ///< 通过sort操作，将f=g+h的最小值放在openList对首
        std::sort(openList.begin(), openList.end(), Astart::compare);
    }

    if (find_path) {
            printPath(cur_node);
            std::cout << std::endl;
    }

    releaseNode(cur_node);
    openList.clear();
    closeList.clear();
    return find_path;
}