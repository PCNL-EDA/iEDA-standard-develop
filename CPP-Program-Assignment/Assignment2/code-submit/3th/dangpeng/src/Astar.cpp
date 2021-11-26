/**
 * @file Astar.cpp
 * @brief Read and display the information of the input file.
 * @author DANGPENG (dangpeng21@mails.ucas.ac.cn)
 * @version 1.0
 * @date 2021-11-08
 * @copyright Copyright (c) 2021  DANGPENG
 */
#include "../include/Astar.h"

int main()
{
    int maze[ROWS][COLS] = {
        {0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}};
    Node beginPosition = {0, 0};
    Node endPosition = {3, 7};
    treeNode *pRoot = NULL;
    vector<treeNode *> buff;
    pathNode pathMap[ROWS][COLS] = {0};
    pathMap[beginPosition.row][beginPosition.col].isFind = true;
    pRoot = new treeNode;
    memset(pRoot, 0, sizeof(pRoot));
    pRoot->pos = beginPosition;
    treeNode *pCurrent = pRoot;
    vector<treeNode *>::iterator it;
    vector<treeNode *>::iterator itMin;
    bool isFindEnd = false;
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            treeNode *pTemp = new treeNode;
            memset(pTemp, 0, sizeof(pTemp));
            pTemp->pos = pCurrent->pos;
            switch (i)
            {
            case p_up:
                pTemp->pos.row--;
                pTemp->pos.g += StraightLineCost;
                break;
            case p_down:
                pTemp->pos.row++;
                pTemp->pos.g += StraightLineCost;
                break;
            case p_left:
                pTemp->pos.col--;
                pTemp->pos.g += StraightLineCost;
                break;
            case p_right:
                pTemp->pos.col++;
                pTemp->pos.g += StraightLineCost;
                break;
            case p_lup:
                pTemp->pos.col--;
                pTemp->pos.row--;
                pTemp->pos.g += SlashLineCost;
                break;
            case p_ldown:
                pTemp->pos.col--;
                pTemp->pos.row++;
                pTemp->pos.g += SlashLineCost;
                break;
            case p_rup:
                pTemp->pos.col++;
                pTemp->pos.row--;
                pTemp->pos.g += SlashLineCost;
                break;
            case p_rdown:
                pTemp->pos.col++;
                pTemp->pos.row++;
                pTemp->pos.g += SlashLineCost;
                break;
            }
            if (pathMap[pTemp->pos.row][pTemp->pos.col].isFind != true &&
                maze[pTemp->pos.row][pTemp->pos.col] != 1 && pTemp->pos.row >= 0 && pTemp->pos.row < ROWS &&
                pTemp->pos.col >= 0 && pTemp->pos.col < COLS)
            {
                pTemp->pos.h = compute_H(endPosition, pTemp->pos);

                pTemp->pos.compute_F();

                pCurrent->pArray.push_back(pTemp);
                pTemp->pParent = pCurrent;

                buff.push_back(pTemp);
            }
            else
            {
                delete pTemp;
            }
        }
        itMin = buff.begin();
        for (it = buff.begin(); it != buff.end(); it++)
        {
            itMin = (((*itMin)->pos.f < (*it)->pos.f) ? itMin : it);
        }
        pCurrent = *itMin;
        pathMap[pCurrent->pos.row][pCurrent->pos.col].isFind = true;
        buff.erase(itMin);
        if (pCurrent->pos.row == endPosition.row &&
            pCurrent->pos.col == endPosition.col)
        {
            isFindEnd = true;
            break;
        }
        if (0 == buff.size())
            break;
    }
    if (isFindEnd)
    {
        printf("Find The End!\n");
        while (pCurrent->pParent)
        {
            printf("(%d,%d) ", pCurrent->pos.row, pCurrent->pos.col);
            pCurrent = pCurrent->pParent;
        }
        printf("\n");
    }

    return 0;
}
