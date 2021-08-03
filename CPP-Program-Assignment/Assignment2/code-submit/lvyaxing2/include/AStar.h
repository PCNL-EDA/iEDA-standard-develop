/**
 * @file Astar.h
 * @author lvyaxing 
 * @brief class and function declaration
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _INCLUDE_STAR_H_
#define _INCLUDE_STAR_H_

#include <vector>
#include <list>
#include<cmath>
#include"Node.h"
//using namespace std;
namespace MyAStar{
	enum cost
	{
        kCost1 = 10,///<Move one grid horizontally
	    kCost2 = 14 ///<Move diagonally one grid horizontally
	};
/**
 * @brief Algorithm class:function declaration and definition
 * 
 */
    class AStar
	{
		public:
		AStar(const std::vector<std::vector<int>>&_obstacle):_obstacle_list(_obstacle){}
	    ~AStar(){
			free();
			}
	    std::list<Node*>getPath(Node &startNode,Node &goalNode,bool isIgnoreCorner);
	    int calcG(Node*start,Node*node);
	    int calcH(Node*node,Node*goal);
	    int calcF(Node*node);
	    Node* findPath(Node &startNode,Node &goalNode,bool isIgnoreCorner);
	    std::vector<Node*>getNearNodes(const Node *node,bool isIgnoreCorner);
	    bool isCanReach(const Node*node,const Node *goal,bool isIgnoreCorner)const;
	    Node *isInList (const std::list <Node*>&list,const Node*node)const;
	    Node *getNearestNode();
        void free();
		private:
	    Node *_start_node=nullptr;
		Node *_goal_node=nullptr;
		Node *_curr_node=nullptr;
	    std::vector<std::vector<int>>_obstacle_list;
	    std::list<Node*>_open_list;
	    std::list<Node*>_close_list;
	};

}//namespace MyAStar
#endif  //_INCLUDE_ASTAR_H
