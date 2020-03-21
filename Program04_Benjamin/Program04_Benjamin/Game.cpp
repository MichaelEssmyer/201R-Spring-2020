#include "Board.h"

#include <iostream>

#include <string>


using namespace std;
int main()
{
	Player *player1, *player2;
	string playername1= "", playername2="";
	string decision;
	bool con = true;
	cout << "WELCOME TO TIC-TAC-TOE GAME" << endl << endl;
	cout << "Enter the name of player 1: ";
	getline(cin, playername1);

	cout << endl;
	cout << "Enter the name of player 2: ";
	getline(cin, playername2);
	while (con)
	{		
		cout << endl << endl;
		player1 = new Player(playername1, "x");
		player2 = new Player(playername2, "o");
		Board* board = new Board(player1, player2);
		board->rungame();
		cout << endl << "Do you want to play again? (Press any key to play, N to exit) " << endl;
		cin >> decision;
		if (decision == "N" or decision =="n")
		{
			con = false;
		}
		else
		{
			con = true;
		}
		
		

	}
	system("pause");


	return 0;
}