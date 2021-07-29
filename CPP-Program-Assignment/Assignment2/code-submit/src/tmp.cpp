/**
 * @file tmp.cpp
 * @author lvyaxing (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "tmp.hpp"

//int tmp::add(int a, int b) { return a + b; }
//#include"/home/litar/Project/include/Astar.h"
//#include"../include/Astar.h"
#include<iostream>
#include<cmath>
using namespace std;

Node::Node(int a,int b):x(a),y(b),F(0),G(0),H(0),parent(NULL){}
int Node::getX()const{return x;}
int Node::getY()const{return y;}
Node* Node::getParent()const{return parent;}
void Node::setParent(Node *_parent){parent=_parent;}
Astar::Astar(const vector<vector<int>>&_obstacle)
             :obstaclelist(_obstacle){}
int Astar::calcG(Node *__start, Node *node)
{
	int extraG = (abs(node->getX()-__start->getX()) + abs(node->getY() - __start->getY())) == 1 ? kCost1 : kCost2;
	int parentG = node->getParent() == NULL ? 0 : node->getParent()->G; //如果是初始节点，则其父节点是空
	return parentG + extraG;
}
 /**
  * @brief 
  * 
  * @param node 
  * @param goal 
  * @return int 
  */
int Astar::calcH(Node *node, Node *goal)
{
	//欧式距离；
	double a=sqrt((goal->getX() - node->getX())*(goal->getX() - node->getX())+ (goal->getY() - node->getY())*(goal->getY() - node->getY()));
    return a*kCost1;
}
 /**
  * @brief 
  * 
  * @param node 
  * @return int 
  */
int Astar::calcF(Node *node)
{
	return node->G + node->H;
}
 
Node *Astar::getNearestNode()//返回F值最小
{
	if (!openList.empty())
	{
		Node* resNode = openList.front();
		for (Node* node : openList)
		if (node->F<resNode->F)
			resNode = node;
		return resNode;
	}
	return NULL;
}
/**
 * @brief 
 * 
 * @param list 
 * @param node 
 * @return Node* 
 */
Node *Astar::isInList(const std::list<Node *> &list, const Node *node) const
{
	//判断某个节点是否在列表中
	for (Node* p : list)
	if (p->getX() == node->getX()&&p->getY() == node->getY())
		return p;
	return NULL;
}
 
/**
 * @brief 
 * 
 * @param node 
 * @param target 
 * @param isIgnoreCorner 
 * @return true 
 * @return false 
 */
bool Astar::isCanreach(const Node *node, const Node *target, bool isIgnoreCorner) const
{    
	if (target->getX()<0 || target->getX()>obstaclelist.size()-1
		|| target->getY()<0 || target->getY()>obstaclelist[0].size() - 1
		||obstaclelist[target->getX()][target->getY()] == 1
		|| (target->getX() == node->getX()&&target->getY()== node->getY())
		|| isInList(closeList, target)) 
		return false;
	else
	{
		if (abs(node->getX()- target->getX()) + abs(node->getY() - target->getY()) <= 1) //非斜角可以
			return true;
		else
		{
			//斜对角要判断
			if (obstaclelist[node->getX()][target->getY()] <1 || obstaclelist[target->getX()][node->getY()] <1)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}
/**
 * @brief 
 * 
 * @param node 
 * @param isIgnoreCorner 
 * @return vector<Node *> 
 */
 vector<Node *> Astar::getNearnodes(const Node *node, bool isIgnoreCorner) const//找出指定节点周围可达的节点
{
	vector<Node *> Nearnodes;
 
	for (int i = node->getX() - 1&&i>0; i<= node->getX()+ 1; i++)
	for (int j = node->getY() - 1&&j>0; j<= node->getY()+ 1; j++)
	if (isCanreach(node, new Node(i, j), isIgnoreCorner))
		Nearnodes.push_back(new Node(i, j));
 
	return Nearnodes;
}
/**
 * @brief 
 * 
 * @param _startNode 
 * @param _goalNode 
 * @param isIgnoreCorner 
 * @return Node* 
 */
Node *Astar::findPath(Node &_startNode, Node &_goalNode, bool isIgnoreCorner)
{
	openList.push_back(new Node(_startNode.getX(), _startNode.getY())); //放入起点,拷贝一个起点，开始寻找路径
	while (!openList.empty())
	{
		Node* curNode =getNearestNode(); //找到F值最小的点
		openList.remove(curNode); //从开启列表中删除
		closeList.push_back(curNode); //放到关闭列表
		//找到当前周围八个节点中可以通过的节点
		vector<Node*> surroundNodes = getNearnodes(curNode, isIgnoreCorner);
		for (Node *target : surroundNodes)
		{
			//2,对某一个节点，如果它不在开启列表中，加入到开启列表，设置当前节点为其父节点，计算F G H
			if (!isInList(openList, target))
			{
				target->setParent(curNode);
 
				target->G = calcG(curNode, target);
				target->H = calcH(target, &_goalNode);
				target->F = calcF(target);
 
				openList.push_back(target);
			}
			//3，对某一个节点，它在开启列表中，计算G值, 如果比原来的大, 就什么都不做, 否则设置它的父节点为当前点,并更新G和F
			else
			{
				int tempG = calcG(curNode, target);
				if (tempG<target->G)
				{
					target->setParent(curNode);
 
					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Node *resNode = isInList(openList, &_goalNode);//判断终点是否在开启列表
			if (resNode)
				return resNode; //返回列表里的节点指针，
		}
	}
 
	return NULL;
}
/**
 * @brief 
 * 
 * @param _startNode 
 * @param _goalNode 
 * @param isIgnoreCorner 
 * @return list<Node *> 
 */
list<Node *> Astar::getPath(Node &_startNode, Node &_goalNode, bool isIgnoreCorner)
{
	Node  *result = findPath(_startNode, _goalNode, isIgnoreCorner);
	list<Node *> path;
	//返回路径，如果没找到路径，返回空
	while (result)
	{
		path.push_front(result);
		result = result->getParent();
		//result->setParent(result);


	}
 
	// 清空临时开闭列表，
	openList.clear();
	closeList.clear();
 
	return path;
}
 


 
