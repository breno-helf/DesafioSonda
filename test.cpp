#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>
#include "robot.hpp"
#include "grid.hpp"
using namespace std;

const int DIR_CHAR[] = {'N', 'E', 'S', 'W'};

/*
  Converts a char direction into a number direction
*/
int dir_num(char c) {
    if (c == 'N') {
	return 0;
    } else if (c == 'E') {
	return 1;
    } else if (c == 'S') {
	return 2;
    } else if (c == 'W') {
	return 3;
    } else {
	cerr << "Direction char " << c << " not supported\n";
	exit(-1);
    }
}

/*
  Converts a number direction into a char direction
*/
char dir_char(int d) {
    if (d < 0 || d > 3) {
	cerr << "Direction num " << d << " not supported\n";
	exit(-1);
    }
    return DIR_CHAR[d];
}

int main() {
    Grid G = Grid(6, 6);
    
    vector<Robot> v;
    vector<string> str;
    vector<Robot> ans;
    vector<int> dist;
    v.push_back(Robot(1, 2, 0));
    v.push_back(Robot(3, 3, 1));
    str.push_back("LMLMLMLMM");
    str.push_back("MMRMMRMRRM");
    ans.push_back(Robot(1, 3, 0));
    ans.push_back(Robot(5, 1, 1));
    dist.push_back(8);
    dist.push_back(9);
    for (int i = 0; i < 2; i++) {
	Robot R = v[i];
	R.execute_commands(G, str[i]);
	assert(R == ans[i]);
	assert(R.min_dist(G, R.x, R.y, R.d) == 0);
	assert(R.min_dist(G, 0, 0, 0) == dist[i]);
    }

    G.print_grid();
    
    return 0;
}
