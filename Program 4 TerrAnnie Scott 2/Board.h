#pragma once
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Player.h"

using namespace std;

struct Tile {
	string tile;
	bool CheckTitle(string myArr[], int index); //Check title
	bool CheckWinner(Tile myArr[], string symbol);

};

class Board {
public:
	void createBoard();
	void PrintBoard();
	void playerTurn();
	Tile board[9];
	Player names[2];
	void GetName();
	void Output(int Round);
	int PlayAgain();
	

	
};