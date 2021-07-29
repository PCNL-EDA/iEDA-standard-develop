// a-star.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "project/map2d.h"
#include "project/astar.h"

int main()
{
	std::vector<std::vector<char>> rawmap = {
		{'s', ' ', ' ', ' ', 'x', 'x', 'x', 'x'},
		{' ', ' ', ' ', ' ', ' ', 'x', 'x', 'x'},
		{'x', 'x', ' ', 'x', 'x', ' ', ' ', ' '},
		{'x', ' ', ' ', ' ', ' ', ' ', ' ', 'e'}
	};
	std::vector<location2d> move = {
		location2d(-1,0),
		location2d(-1,-1),
		location2d(0,-1),
		location2d(1,-1),
		location2d(1,0),
		location2d(1,1),
		location2d(0,1),
		location2d(-1,1),
	};
	map2d amap(rawmap, move, location2d(0, 0), location2d(7, 3));
	pathsolver* abc_solver = new astar();
	bool has_solve = abc_solver->solve(amap);

	if (has_solve) {
		printf("ok: ");
		std::vector<location2d> path = abc_solver->get_path();
		for (int i = 0; i < path.size(); i++) {
			printf("->(%d,%d) ", path[i].y, path[i].x);
		}
	}
	else {
		printf("not ok");
	}

	delete abc_solver;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

