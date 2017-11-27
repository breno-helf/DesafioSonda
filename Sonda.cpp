#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

const int DIR_CHAR[] = {'N', 'E', 'S', 'W'};

struct Robot {
    int x, y, d;
    Robot(int X = 0, int Y = 0, int D = 0):
	x(X), y(Y), d(D) {}    
};

Robot execute_commands(Robot R, std::string& commands) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for (int i = 0; i < (int)commands.size(); i++) {
	char c = commands[i];
	if (c == 'L') {
	    R.d = (R.d + 3) % 4;
	} else if (c == 'R') {
	    R.d = (R.d + 1) % 4;
	} else if (c == 'M') {
	    R.x += dx[R.d];
	    R.y += dy[R.d];
	} else {
	    std::cerr << "Command " << c << " not supported\n";
	    exit(-1);
	}
    }

    return R;
}

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
	std::cerr << "Direction char " << c << " not supported\n";
	exit(-1);
    }
}

char dir_char(int d) {
    if (d < 0 || d > 3) {
	std::cerr << "Direction num " << d << " not supported\n";
	exit(-1);
    }
    return DIR_CHAR[d];
}

int main() {
    // N and M are the dimensions of the grid
    int N, M;
    std::cin >> N >> M;

    
    Robot R;
    int x, y;
    char d;
    std::string commands;
    
    while (std::cin >> x >> y >> d) {	
	R = Robot(x, y, dir_num(d));
	std::cin >> commands;
	R = execute_commands(R, commands);
	std::cout << R.x << ' ' << R.y << ' ' << dir_char(R.d) << '\n';
    }
    
    return 0;
}
