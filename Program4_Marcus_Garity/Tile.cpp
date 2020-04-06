#include "Tile.h"

Tile::Tile() {}

Tile::Tile(int row, int col) {

	this->row =row;
	this->col =col;
	this->mark = ' ';
	this->available = true;
}


Tile::~Tile() {
}




