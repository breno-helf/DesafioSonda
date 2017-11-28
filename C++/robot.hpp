#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include "grid.hpp"

using namespace std;

class Robot {
 public:
    int x, y, d;
    Robot(int X, int Y, int D);
    Robot();
    /*
      Execute the coomands in the string, if the command is to an
      invalid position, it just ignores the command.
      At the end, set the position at the grid where the "sonda" is
      to 1 (Which is occupied).
    */
    void execute_commands(Grid & G, string & commands);

    /*
      Function that calculates the current position of the robot
      to the position X, Y, D.
      Just does a simple BFS.
    */
    int min_dist(Grid & G, int X, int Y, int D);

    bool operator < (const Robot ot) const {
	if (x != ot.x) return (x < ot.x);
	else if (y != ot.y) return (y < ot.y);

	return (d < ot.d);
    }
    
    bool operator == (const Robot ot) const {
	return (x == ot.x && y == ot.y && d == ot.d);
    }
};

#endif
