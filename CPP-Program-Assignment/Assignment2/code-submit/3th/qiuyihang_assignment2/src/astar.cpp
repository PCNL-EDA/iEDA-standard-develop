/**
 * @file astar.cpp
 * @brief Core algorithm, using A* algorithm for pathfinding.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "astar.h"
#include <time.h>

namespace algorithms {

bool SortCompare(const Point *point1, const Point *point2) {
  return point1->f_ < point2->f_;
}

Point *AStar::findWay(Point *beginpoint, Point *endpoint,
                      vector<vector<Point *>> &allpoints,
                      resource::Display &display) {
#ifndef _GTEST
  printf("\e[0;32m[SUCCESS]\033[0m point->findWay(): Finding the shortest path "
         "using AStar Algorithms.\n"
         "\e[0;34mThe startpoint:[%d][%d] ---> The endpoint:[%d][%d]\033[0m\n",
         beginpoint->x_, beginpoint->y_, endpoint->x_, endpoint->y_);
#endif
  clock_t start_time = clock();
  allpoints_ = allpoints;
  endpoint_ = endpoint;
  if (endpoint_->type_ == Type::TYPE_BARRIER) {
    printf("The end point is an obstacle.\n");
    findway_ = false;
    return nullptr;
  }
  if (*endpoint_ == *beginpoint) {
    printf("The start and end points are the same.\n");
    findway_ = false;
    return nullptr;
  }
  openlist_.push_back(beginpoint);
  beginpoint->type_ = Type::TYPE_OPENED;
  beginpoint->f_ = getFOctagonal(beginpoint);
  int step_count = 0;
  do {
    ++step_count;
    curpoint_ = openlist_[0];
#ifndef _GTEST
    printf("\e[0;34mStep %d: point[%d][%d] is selected\033[0m \n", step_count,
           curpoint_->x_, curpoint_->y_);
#endif

    openlist_.erase(openlist_.begin());
    curpoint_->type_ = Type::TYPE_CLOSED;
    closelist_.push_back(curpoint_);
    if (*curpoint_ == *endpoint_) {
      clock_t end_time = clock();
      findway_ = true;
#ifndef _GTEST
      printf("Found way and end searching.\n");
      printf("\e[0;34mThe runtime of A* algorithm is %ld ms.\033[0m \n",
             end_time - start_time);
#endif
      return curpoint_;
    }
    vector<Point *> nevec = getNeighboringPoint(curpoint_, display);
    computeNeighboringValue(nevec, openlist_);
    sort(openlist_.begin(), openlist_.end(), SortCompare);
  } while (openlist_.size() > 0);
  printf("\e[0;32m[FAILURE]\033[0m Can not find way.\n");
  findway_ = false;
  return nullptr;
}

vector<Point *> AStar::getNeighboringPoint(Point *point,
                                           resource::Display &display) {
  neighbourlist_.clear();
  getRightUpNeighboringPoint(point, display);
  getRightDownNeighboringPoint(point, display);
  getRightNeighboringPoint(point, display);
  getUpNeighboringPoint(point, display);
  getLeftDownNeighboringPoint(point, display);
  getLeftUpNeighboringPoint(point, display);
  getLeftNeighboringPoint(point, display);
  getDownNeighboringPoint(point, display);
  return neighbourlist_;
}

void AStar::getLeftDownNeighboringPoint(Point *point,
                                        resource::Display &display) {
  if (point->x_ > 0 && point->y_ > 0) {
    if (allpoints_[point->x_ - 1][point->y_ - 1]->type_ != Type::TYPE_BARRIER) {
      if (!(allpoints_[point->x_ - 1][point->y_]->type_ == Type::TYPE_BARRIER &&
            allpoints_[point->x_][point->y_ - 1]->type_ ==
                Type::TYPE_BARRIER)) {
        allpoints_[point->x_ - 1][point->y_ - 1]->direction_ =
            Direction::INCLINE;
        neighbourlist_.push_back(allpoints_[point->x_ - 1][point->y_ - 1]);
      }
    }
  }
}

void AStar::getLeftUpNeighboringPoint(Point *point,
                                      resource::Display &display) {
  if (point->x_ > 0 && point->y_ < display.get_max_colunm_() - 1) {
    if (allpoints_[point->x_ - 1][point->y_ + 1]->type_ != Type::TYPE_BARRIER) {
      if (!(allpoints_[point->x_ - 1][point->y_]->type_ == Type::TYPE_BARRIER &&
            allpoints_[point->x_][point->y_ + 1]->type_ ==
                Type::TYPE_BARRIER)) {
        allpoints_[point->x_ - 1][point->y_ + 1]->direction_ =
            Direction::INCLINE;
        neighbourlist_.push_back(allpoints_[point->x_ - 1][point->y_ + 1]);
      }
    }
  }
}

void AStar::getRightUpNeighboringPoint(Point *point,
                                       resource::Display &display) {
  if (point->x_ < display.get_max_row_() - 1 &&
      point->y_ < display.get_max_colunm_() - 1) {
    if (allpoints_[point->x_ + 1][point->y_ + 1]->type_ != Type::TYPE_BARRIER) {
      if (!(allpoints_[point->x_ + 1][point->y_]->type_ == Type::TYPE_BARRIER &&
            allpoints_[point->x_][point->y_ + 1]->type_ ==
                Type::TYPE_BARRIER)) {
        allpoints_[point->x_ + 1][point->y_ + 1]->direction_ =
            Direction::INCLINE;
        neighbourlist_.push_back(allpoints_[point->x_ + 1][point->y_ + 1]);
      }
    }
  }
}

void AStar::getRightDownNeighboringPoint(Point *point,
                                         resource::Display &display) {
  if (point->x_ < display.get_max_row_() - 1 && point->y_ > 0) {
    if (allpoints_[point->x_ + 1][point->y_ - 1]->type_ != Type::TYPE_BARRIER) {
      if (!(allpoints_[point->x_ + 1][point->y_]->type_ == Type::TYPE_BARRIER &&
            allpoints_[point->x_][point->y_ - 1]->type_ ==
                Type::TYPE_BARRIER)) {
        allpoints_[point->x_ + 1][point->y_ - 1]->direction_ =
            Direction::INCLINE;
        neighbourlist_.push_back(allpoints_[point->x_ + 1][point->y_ - 1]);
      }
    }
  }
}

void AStar::getRightNeighboringPoint(Point *point, resource::Display &display) {
  if (point->x_ < display.get_max_row_() - 1) {
    if (allpoints_[point->x_ + 1][point->y_]->type_ != Type::TYPE_BARRIER) {
      allpoints_[point->x_ + 1][point->y_]->direction_ = Direction::MANHATTAN;
      neighbourlist_.push_back(allpoints_[point->x_ + 1][point->y_]);
    }
  }
}

void AStar::getLeftNeighboringPoint(Point *point, resource::Display &display) {
  if (point->x_ > 0) {
    if (allpoints_[point->x_ - 1][point->y_]->type_ != Type::TYPE_BARRIER) {
      allpoints_[point->x_ - 1][point->y_]->direction_ = Direction::MANHATTAN;
      neighbourlist_.push_back(allpoints_[point->x_ - 1][point->y_]);
    }
  }
}

void AStar::getUpNeighboringPoint(Point *point, resource::Display &display) {
  if (point->y_ < display.get_max_colunm_() - 1) {
    if (allpoints_[point->x_][point->y_ + 1]->type_ != Type::TYPE_BARRIER) {
      allpoints_[point->x_][point->y_ + 1]->direction_ = Direction::MANHATTAN;
      neighbourlist_.push_back(allpoints_[point->x_][point->y_ + 1]);
    }
  }
}

void AStar::getDownNeighboringPoint(Point *point, resource::Display &display) {
  if (point->y_ > 0) {
    if (allpoints_[point->x_][point->y_ - 1]->type_ != Type::TYPE_BARRIER) {
      allpoints_[point->x_][point->y_ - 1]->direction_ = Direction::MANHATTAN;
      neighbourlist_.push_back(allpoints_[point->x_][point->y_ - 1]);
    }
  }
}

void AStar::computeNeighboringValue(vector<Point *> &nevec,
                                    vector<Point *> &openlist_) {
  for (int i = 0; i < nevec.size(); ++i) {
    auto tmpoint = nevec[i];
    if (tmpoint->type_ == Type::TYPE_CLOSED) {
      continue;
    }
    if (tmpoint->type_ != Type::TYPE_OPENED) {
      tmpoint->parent_ = curpoint_;
      if (tmpoint->direction_ == Direction::MANHATTAN) {
        tmpoint->g_ = curpoint_->g_ + kManhattanMoveCost;
#ifndef _GTEST
        printf("point[%d][%d]:\tvalue_G=%d", tmpoint->x_, tmpoint->y_,
               tmpoint->g_);
#endif
      } else if (tmpoint->direction_ == Direction::INCLINE) {
        tmpoint->g_ = curpoint_->g_ + kInclineMoveCost;
#ifndef _GTEST
        printf("point[%d][%d]:\tvalue_G=%d", tmpoint->x_, tmpoint->y_,
               tmpoint->g_);
#endif
      }
      tmpoint->h_ = getHOctagonal(tmpoint);
      tmpoint->f_ = getFOctagonal(tmpoint);
#ifndef _GTEST
      printf("\tvalue_H=%d\tvalue_F=%d\n", tmpoint->h_, tmpoint->f_);
#endif
      openlist_.push_back(tmpoint);
      tmpoint->type_ = Type::TYPE_OPENED;
    } else {
      if (tmpoint->h_ < curpoint_->h_) {
        tmpoint->parent_ = curpoint_;
        if (tmpoint->direction_ == Direction::MANHATTAN) {
          tmpoint->g_ = curpoint_->g_ + kManhattanMoveCost;
        } else if (tmpoint->direction_ == Direction::INCLINE) {
          tmpoint->g_ = curpoint_->g_ + kInclineMoveCost;
        }
        tmpoint->f_ = getFOctagonal(tmpoint);
      }
#ifndef _GTEST
      printf("point[%d][%d]:\tvalue_G=%d\tvalue_H=%d\tvalue_F=%d\n",
             tmpoint->x_, tmpoint->y_, tmpoint->g_, tmpoint->h_, tmpoint->f_);
#endif
    }
  }
}

} // namespace algorithms
