#include "robot.hpp"

Robot::Robot(int X = 0, int Y = 0, int D = 0) {
    this->x = X;
    this->y = Y;
    this->d = D;
}

Robot::Robot() {
    this->x = 0;
    this->y = 0;
    this->d = 0;
}

void Robot::execute_commands(Grid & G, string & commands) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for (int i = 0; i < (int)commands.size(); i++) {
	char c = commands[i];
	if (c == 'L') {
	    this->d = (this->d + 3) % 4;
	} else if (c == 'R') {
	    this->d = (this->d + 1) % 4;
	} else if (c == 'M') {
	    if (G.valid(this->x + dx[this->d], this->y + dy[this->d])) {
		this->x += dx[this->d];
		this->y += dy[this->d];
	    }
	} else {
	    cerr << "Command " << c << " not supported\n";
	    exit(-1);
	}
    }
    G.set_position(this->x, this->y);
}
