#include "grid.hpp"

Grid::Grid(int N, int M) {
    this->n = N;
    this->m = M;
    this->matrix.resize(N);
    for (int i = 0; i < n; i++) {
	matrix[i].resize(M);
    }
}

Grid::Grid() {
    this->n = 0;
    this->m = 0;
}

bool Grid::valid(int x, int y) {
    
    if (x >= 0 && x < (int)(this->matrix.size()) &&
	y >= 0 && y < (int)(this->matrix[0].size())) {
	return (this->matrix[x][y] == 0);
    }

    return false;
}

void Grid::set_position(int x, int y) {
    if (this->valid(x, y)) {
	this->matrix[x][y] = 1;
    }
}
