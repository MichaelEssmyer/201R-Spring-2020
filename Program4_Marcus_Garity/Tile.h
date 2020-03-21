#ifndef _TILE_H
#define _TILE_H


struct Tile {

	Tile();
	Tile(int, int);
	~Tile();
	int row;
	int col;
	bool available;
	char mark;

};





#endif