#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Player.h"

class Board {
public:	
	Board();
	//Initialized booard.
	Board(Player* Player1, Player* Player2);
	// plays the game loop.
	void PlayGame();
	~Board();
	

private:

	//Prints File
	void PrintFile();
	//Clears Board for Next Round
	void ClearBoard();
	//Runs all Check Win conditions
	bool CheckWin(char);
	//checks right diagonal win condition
	bool CheckRightDiagonal(char);
	//check left diagonal win considition
	bool CheckLeftDiagonal(char);
	//checks horizontal win condition
	bool CheckHorizontal(char);
	//check vetircal win considtion
	bool CheckVertical(char);
	//diplays board to screen
	void DisplayBoard();
	Player * Player_array[2];
	Tile * Tile_array[9];
	
};




#endif 

