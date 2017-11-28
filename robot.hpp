#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
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
      to 1.
    */
    void execute_commands(Grid & G, string & commands);    
};

#endif
