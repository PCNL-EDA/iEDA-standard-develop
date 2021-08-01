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
		void set_F(int f){_F=f;}
		void set_G(int g){_G=g;}
		void set_H(int h){_H=h;}
		int get_F()const{return _F;}
		int get_G()const{return _G;}
		int get_H()const{return _H;}
	    Node* get_parent_node()const{return _parent_node;}
	    void set_parent_node(Node *_parent){_parent_node=_parent;}
	   
    
	    private:
	    int _x,_y;
		Node* _parent_node; 
		int _F,_G,_H;

    };
}// namespace MyAStar

#endif  // _INCLUDE_NODE_H_