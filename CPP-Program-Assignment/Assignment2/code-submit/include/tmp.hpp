#ifndef TMP_TMP_H_
#define TMP_TMP_H_

/*namespace tmp
{
  int add(int, int);
}*/

/*

*/
#include <vector>
#include <list>
//#include<iostream>
using namespace std;

const int kCost1 = 10; //横着移动一格消耗
const int kCost2 = 14; //对角横移一格消耗
class Node {
	private:
	int x,y;
    public:
	int F,G,H;
    Node* parent;
    Node(int a,int b);
	int getX()const;
	int getY()const;
	Node* getParent()const;
	void setParent(Node *_parent);
};
class Astar{
	private:
	Node* startNode,*goalNode;//开始节点，结束节点
	vector<vector<int>>obstaclelist;//障碍图
	list<Node*>openList;
	list<Node*>closeList;
	int calcG(Node*__start,Node*node);
	int calcH(Node*node,Node*goal);
	int calcF(Node*node);
	Node* findPath(Node &_startNode,Node &_goalNode,bool isIgnoreCorner);
	vector<Node*>getNearnodes(const Node *node,bool isIgnoreCorner)const;
	bool isCanreach(const Node*node,const Node*goal,bool isIgnoreCorner)const;
	Node *isInList (const list <Node*>&list,const Node*node)const;
	Node *getNearestNode();
	public:
	Astar(const vector<vector<int>>&_obstacle);
	list<Node*>getPath(Node &_startNode,Node &_goalNode,bool isIgnoreCorner);
	~Astar(){}
	
    
};



#endif  // TMP_TMP_H_
