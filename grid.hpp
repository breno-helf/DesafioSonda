#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Grid {
 public:
    int n, m;
    Grid(int N, int M);
    Grid();
    /*
      Returns true if a position is valid
      i.e if it is inside the grid and there is no "sonda" there
    */
    bool valid(int x, int y);

    /*
      Sets position x, y to 1 (which means occupied position)
    */
    void set_position(int x, int y);
 private:
    vector< vector <int> > matrix;
};

#endif
