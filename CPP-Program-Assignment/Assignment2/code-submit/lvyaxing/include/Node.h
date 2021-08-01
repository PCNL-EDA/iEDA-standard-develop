/**
 * @file Node.h
 * @author lvyaxing
 * @brief 
 * @version 0.1
 * @date 2021-08-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _INCLUDE_NODE_H_
#define _INCLUDE_NODE_H_

namespace MyAStar {
	/**
     * @brief Contains the coordinates of the node and the parent node,and Three data required by the algorithm class
     * @class Node
    */
	class Node 
	{
		public:
	    Node(int a,int b):_x(a),_y(b),_F(0),_G(0),_H(0),_parent_node(nullptr){}
        ~Node(){_parent_node = nullptr; }
	    int get_x()const{return _x;}
	    int get_y()const{return _y;}
	    Node* get_parent_node()const{return _parent_node;}
	    void set_parent_node(Node *_parent){_parent_node=_parent;}
	    int _F,_G,_H;
        Node* _parent_node;

	    private:
	    int _x,_y;

    };
}// namespace MyAStar

#endif  // _INCLUDE_NODE_H_