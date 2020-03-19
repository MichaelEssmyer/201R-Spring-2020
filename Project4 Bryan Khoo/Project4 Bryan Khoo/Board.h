#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include <fstream>

//class Board 
class Board {
public: 
	//all class method declarations 
	Board();
	void PrintBoard();
	bool CheckSpace(Tile playerPosition);
	void SetTile(char player);
	bool CheckForWinner(char playerSymbol);
	void RunGame();
	void SaveGame(std::ofstream& fout, Player* player[]);
private:
	//declare 2-d array with size 3 for tic-tac-toe board 
	char tileArray[3][3];
	//declare Tile as player's position. This will be used to store player's desired location to place their symbol
	Tile playerPosition;
	//declare an array of size 2 that contains Player object pointers
	Player* players[2];
};