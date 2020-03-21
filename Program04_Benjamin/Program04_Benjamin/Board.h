#ifndef BOARD_H
#define BOARD_H
#include "Player.h"

struct tile
{
	string mark="";
	bool available = true;
};

class Board : public Player
{
	public:
		Board(Player* P1, Player* P2);
		void rungame();
		int CheckWinner(string symbol);
		void PrintBoard();
		void SaveGame();
		void ClearFile();
		

	private:
		tile The_Board[3][3];
		Player *the_player[2];
};




#endif

