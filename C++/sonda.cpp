#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
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
    // N and M are the dimensions of the grid
    int N, M;
    Grid G;
    cin >> N >> M;

    G = Grid(N + 1, M + 1);

    
    Robot R;
    int x, y;
    char d;
    string commands;

    /*
      Read the input.
      We always assume that the "sonda" will start at an empty position
    */
    while (cin >> x >> y >> d) {	
	R = Robot(x, y, dir_num(d));
	cin >> commands;
	R.execute_commands(G, commands);
	cout << R.x << ' ' << R.y << ' ' << dir_char(R.d) << '\n';
    }
    
    return 0;
}
