/**
 * @file Astar.h
 * @brief Read and display the information of the input file.
 * @author DANGPENG (dangpeng21@mails.ucas.ac.cn)
 * @version 1.0
 * @date 2021-11-08
 * @copyright Copyright (c) 2021  DANGPENG
 */
#pragma once
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define ROWS 9
#define COLS 10
#define StraightLineCost 10
#define SlashLineCost 14

class Node
{
public:
    int row;
    int col;
    int f;
    int g;
    int h;

public:
    int compute_F()
    {
        f = g+h;
        return f;
    }

};


class treeNode
{
public:
    Node pos;
    treeNode *pParent;
    vector<treeNode *> pArray;
};

class pathNode
{
public:
    bool isFind;
};

int compute_H(const Node& endPosition, const Node& pos)
{
    int x = ((endPosition.col > pos.col) ? (endPosition.col - pos.col) : (pos.col - endPosition.col));
    int y = ((endPosition.row > pos.row) ? (endPosition.row - pos.row) : (pos.row - endPosition.row));
    return (x + y) * StraightLineCost;
}

enum direct
{
    p_up,
    p_down,
    p_left,
    p_right,
    p_lup,
    p_ldown,
    p_rup,
    p_rdown
};