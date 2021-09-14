#include <map>

#include "Grid.hpp"
void AStarSearch(Grid, Point, Point);
bool minCompare(std::pair<Point, int>, std::pair<Point, int>);
Point popMinFrontierPoint(std::map<Point, int>& frontier);