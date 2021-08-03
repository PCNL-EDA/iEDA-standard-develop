/**
 * @file Astar.cpp
 * @author lvyaxing 
 * @brief  Definitions of major function
 * @version 0.1
 * @date 2021-07-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/AStar.h"
#include<iostream>
#include<cmath>
#include<vector>
namespace MyAStar{
	/**
    * @fn calcaG
    * @brief Calculates the distance from a specific node to the starting node:G
    * @param start 
    * @param node 
    * @return int 
    */
    int AStar::calcG(Node *start, Node *node)
    {   int extraG, parentG;
		if((abs(node->get_x()-start->get_x()) + abs(node->get_y()-start->get_y())) == 1 )
	    {
			extraG=cost::kCost1;
		}
			else 
			{
				extraG=cost::kCost2;
			}
		if(node->get_parent_node() != nullptr)
		{
		    parentG =node->get_parent_node()->get_G();
		}
		else 
		{
			parentG =0;
		}
	    return parentG + extraG;
    }
    /**
     * @brief 
     * @fn calcH Calculates the distance from a specific node to the ending node :H
     * @param node 
     * @param goal 
     * @return int 
     */
     int AStar::calcH(Node *node, Node *goal)
	 {
	     double a=abs(goal->get_x() - node->get_x())+ abs(goal->get_y() - node->get_y());///<Manhattan distance
         return a*cost::kCost1;
     }
    /**
     * @brief F=G+H; Use F to select node
     * @fn  calcF
     * @param node 
     * @return int 
     */
     int AStar::calcF(Node *node)
     {
	     return node->get_G() + node->get_H();
     }
    /**
     * @brief Find the node with the smallest F value around the node
     * @fn getNearestNode
     * @return Node* 
     */
     Node *AStar::getNearestNode()
     {
	     if (!_open_list.empty())
		 {
			 Node* resNode = _open_list.front();
			 for (Node* node : _open_list)
			 {
				 if (node->get_F()<resNode->get_F())
				 {
					 resNode = node;
				 }
			 }
			 return resNode;
	     }    
		 return nullptr;
     }
    /**
     * @brief Determine whether a node is in the list
     * @fn isInList 
     * @param list 
     * @param node 
     * @return Node* 
     */
     Node *AStar::isInList(const std::list<Node *> &list, const Node *node) const
	 {
		 for (Node* p : list)
		 {
			 if (p->get_x() == node->get_x()&&p->get_y() == node->get_y())
			 {
				 return p;
			 }
	     }
	    return nullptr;
     }
 
    /**
     * @brief Judge whether two nodes are reachable
     * @fn isCanReach
     * @param node 
     * @param target 
     * @param isIgnoreCorner 
     * @return true 
     * @return false 
     */
     bool AStar::isCanReach(const Node *node, const Node *target, bool isIgnoreCorner) const
	 {    
		 if (target->get_x()<0 || target->get_x()>_obstacle_list.size()-1)
		 {
			 return false;
		 }
		 if (target->get_y()<0 || target->get_y()>_obstacle_list[0].size() - 1)
		  {
			 return false;
		 }
		 if (_obstacle_list[target->get_x()][target->get_y()] == 1)
		  {
			 return false;
		 }
		 if (target->get_y() == node->get_y()&&target->get_y()== node->get_y())
		  {
			 return false;
		 }
		 if (isInList(_close_list, target))
		{ 
		return false;
		}
		else
		{
			if (abs(node->get_x()- target->get_y()) + abs(node->get_x() - target->get_y()) <= 1) ///<Horizontal or vertical relationship
			{
			return true;
		    }
			else
			{
				///<Judgment of diagonal relationship
				if (_obstacle_list[node->get_x()][target->get_y()]==0 
				|| _obstacle_list[target->get_x()][node->get_y()]==0)
				{
					return true;
			    }
			    else
				{
				return isIgnoreCorner;
				}
		    }
	    }
     }  
    /**
     * @brief Find the reachable nodes around the specified node
     * @fn getNearNodes
     * @param node 
     * @param isIgnoreCorner 
     * @return vector<Node *> 
     */
     std::vector<Node *> AStar::getNearNodes(const Node *node, bool isIgnoreCorner)
	 {
		 std::vector<Node *> Nearnodes;
		 for (int i = node->get_x() - 1&&i>0; i<= node->get_x()+ 1; i++)
		 {
			 for (int j = node->get_y() - 1&&j>0; j<= node->get_y()+ 1; j++)
			 {      
				  _curr_node =new Node(i,j);
				 if (isCanReach(node, _curr_node, isIgnoreCorner))
				 {
					 Nearnodes.push_back(_curr_node);
	             }
	         }
			
	     }
         return Nearnodes;
     } 
    /**
     * @brief  
     * @fn  findPath
     * @param startNode 
     * @param goalNode 
     * @param isIgnoreCorner 
     * @return Node* 
     */
     Node *AStar::findPath(Node &startNode, Node &goalNode, bool isIgnoreCorner)
	 {   ///<Put in the starting node, copy a starting node, and start looking for the path
	      _curr_node =new Node(startNode.get_x(), startNode.get_y());
		 _open_list.push_back(_curr_node);
		 while (!_open_list.empty())
		 {
			 Node* curNode =getNearestNode(); ///<Find the node with the smallest F value
			 _open_list.remove(curNode); ///<Remove from open list
			 _close_list.push_back(curNode); ///<Drop to close list
			 //1.Find the nodes that can pass through the current eight surrounding nodes
			 std::vector<Node*> surroundNodes = getNearNodes(curNode, isIgnoreCorner);
			 for (Node *target : surroundNodes)
			 {
				 //2,For a node, if it is not in the open list, add it to the open list, 
				 //  set the current node as its parent node, and calculate F G H
				 if (!isInList(_open_list, target))
				 {
					 target->set_parent_node(curNode);
					 target->set_G(calcG(curNode, target));
				     target->set_H(calcH(target, &goalNode));
				     target->set_F(calcF(target));
					 _open_list.push_back(target);
			     }
			     ///<3，For a node, if it is in the open list, recalculate the g value. 
				 ///<If it is larger than the original, do nothing. Otherwise, 
				 ///<set its parent node as the current point and update g and F
			     else
				 {
					 int tempG = calcG(curNode, target);
					 if (tempG<target->get_G())
					 {
						 target->set_parent_node(curNode);
						 target->set_G(tempG);
					     target->set_F(calcF(target));
				     }
			     }
			     Node *resNode = isInList(_open_list, &goalNode);///<Judge whether the goal node is in the open list
			     if (resNode)
				 {
					 return resNode; ///<Return the node pointer in the list
			     }
		     }
	     }
         return nullptr;
     }
	/**
     * @brief Output found path
     * @fn getPath
     * @param startNode 
     * @param goalNode 
     * @param isIgnoreCorner 
     * @return list<Node *> 
     */
     std::list<Node *> AStar::getPath(Node &startNode, Node &goalNode, bool isIgnoreCorner)
	 {
		 Node  *result = findPath(startNode, goalNode, isIgnoreCorner);
		 std::list<Node *> path;
		 ///<Returns the path. If the path is not found, it returns null
		 while (result)
		 {
			 path.push_front(result);
			 result = result->get_parent_node();
		 }
		 ///<Clear the temporary opening and closing list,
	     _open_list.clear();
	     _close_list.clear();
         return path;
     }
	 /**
	  * @brief release space
	  * @fn free
	  */
	 void AStar::free()
	 {
       if(_start_node!=nullptr)
			delete _start_node;
			if(_goal_node!=nullptr)
			delete _goal_node;
			if(_curr_node!=nullptr)
			delete _curr_node;
     }

	 
}// namespace MyAStar
