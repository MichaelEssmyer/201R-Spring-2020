#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include "BoardClass.h"
using namespace std;

Board::Board()
{//Default Board constructor calling createBoard()
	createBoard();
}

Board::Board(Player* p1, Player* p2)
{//Constructs the Board object
	srand(time(0));
	createBoard();

	p1 = new Player;
	p2 = new Player;

	players[0] = p1;
	players[1] = p2;

	winner = "Tie";

	//Initializes the player objects
	initializePlayers();
}

Board::~Board()
{//Board object destructor that outputs the final board state before dconstructing the object for another game or program termination
	saveBoard();
	delete players[0];
	delete players[1];
	players[0] = nullptr;
	players[1] = nullptr;
}

void Board::runGame()
{//Runs the game and performs the necessary function calls
	int gameTurn;

	for (gameTurn = 0; gameTurn < 9; gameTurn++)
	{//Runs the game loop
		int plrRow;
		int plrCol;

		system("cls");
		cout << "  \t|_" << players[gameTurn % 2]->getName() << "'s turn_|" << endl << endl;
		printBoard();

		turnHandling(plrRow, plrCol, gameTurn);

		if ( (gameTurn > 3) && checkWinner() )
		{//Checks for a winner after turn 4 since a player cannot win before turn 5
			system("cls");
			winner = players[gameTurn % 2]->getName();
			cout << "\n" << setw(9) << "    " << "GAME OVER" << endl << endl;
			printBoard();
			cout << setw(4) << "    " << winner << " wins this game" << endl << endl;
			break;
		}
		else
			if (gameTurn >= 8)
			{//If no winner has been found by turn 9, the game will be called a draw
				system("cls");
				cout << "\n" << setw(9) << "    " << "GAME OVER" << endl << endl;
				printBoard();
				cout << setw(4) << "    This game is a tie" << endl << endl;
				break;
			}		
	}
}

void Board::initializePlayers()
{//Sets the players' names and game characters
	int pChar = rand() % 2;
	string tempName;

	cout << " Enter a name for Player 1: ";
	getline(cin, tempName);
	players[0]->setName(tempName);

	cout << " Enter a name for Player 2: ";
	getline(cin, tempName);
	players[1]->setName(tempName);

	if (pChar == 0)
	{//Randomly assigns the players a game character
		players[0]->setChar('X');
		players[1]->setChar('O');
	}
	else
	{
		players[0]->setChar('O');
		players[1]->setChar('X');
	}

	//Informs the players of the game character they were assigned
	cout << endl;
	cout << " " << players[0]->getName() << " has been randomly assigned the \'" << players[0]->getChar() << "\' character for this game." << endl;
	cout << " " << players[1]->getName() << " has been randomly assigned the \'" << players[1]->getChar() << "\' character for this game." << endl << endl;
	cout << " Press the ENTER key to continue...";
	cin.get();
}

void Board::checkRowIndex(int& row)
{//Checks that user input will provide a valid array index for the row
	while ((row < 1) || (row > 3))
	{
		cout << endl;
		cout << "\tThat row does not exist. Please Try again." << endl << endl;
		cout << " Select a row: ";
		cin >> row;
	}
}

void Board::checkColIndex(int& col)
{//Checks that user input will provide a valid array index for the column
	while ((col < 1) || (col > 3))
	{
		cout << endl;
		cout << "\tThat column does not exist. Please Try again." << endl << endl;
		cout << " Select a column: ";
		cin >> col;
	}
}

void Board::turnHandling(int& plrRow, int& plrCol, int& gameTurn)
{//Handles the logic for the player turns
	switch (gameTurn % 2)
	{
	case 0:
	{//Handles player 1's turn players[0]
		cout << " Select a row: ";
		cin >> plrRow;
		checkRowIndex(plrRow);
		cout << " Select a column: ";
		cin >> plrCol;
		checkColIndex(plrCol);
		verifyTile(plrRow, plrCol);

		--plrRow;
		--plrCol;
		updateTile(plrRow, plrCol, 0);
		break;
	}
	case 1:
	{//Handles player 2's turn players[1]
		cout << " Select a row: ";
		cin >> plrRow;
		checkRowIndex(plrRow);
		cout << " Select a column: ";
		cin >> plrCol;
		checkColIndex(plrCol);
		verifyTile(plrRow, plrCol);

		--plrRow;
		--plrCol;
		updateTile(plrRow, plrCol, 1);
		break;
	}
	default:
	{//In the event that somehow case 1 and case 2 are both bypassed, the default nullifies the turn and lets the loop continue
		cout << "\n\t\tERROR. Restarting this turn." << endl << endl;
		--gameTurn;
		break;
	}
	}
}

void Board::createBoard()
{//Creates new board and initializes each Tile structure's members
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			tileArray[a][b].isEmpty = true;
			tileArray[a][b].rowPos = a;
			tileArray[a][b].colPos = b;
			tileArray[a][b].currChar = ' ';
		}
	}
}

void Board::printBoard()
{//Prints the current board state
	cout << setw(9) << players[0]->getName() << ": " << players[0]->getChar() << "\t" << players[1]->getName() << ": " << players[1]->getChar() << endl << endl;
	cout << "\t " << tileArray[0][0].currChar << " | " << tileArray[0][1].currChar << " | " << tileArray[0][2].currChar << endl;
	cout << "\t-----------" << endl;
	cout << "\t " << tileArray[1][0].currChar << " | " << tileArray[1][1].currChar << " | " << tileArray[1][2].currChar << endl;
	cout << "\t-----------" << endl;
	cout << "\t " << tileArray[2][0].currChar << " | " << tileArray[2][1].currChar << " | " << tileArray[2][2].currChar << endl << endl;
}

void Board::saveBoard()
{//Saves current board to GameOutput.txt
	ofstream boardOut;

	boardOut.open("GameOutput.txt", ofstream::app);

	boardOut  << "\n" << setw(5) << players[0]->getName() << ": " << players[0]->getChar() << " VS " << players[1]->getName() << ": " << players[1]->getChar() << endl;
	boardOut << "\t " << tileArray[0][0].currChar << " | " << tileArray[0][1].currChar << " | " << tileArray[0][2].currChar << endl;
	boardOut << "\t-----------" << endl;
	boardOut << "\t " << tileArray[1][0].currChar << " | " << tileArray[1][1].currChar << " | " << tileArray[1][2].currChar << endl;
	boardOut << "\t-----------" << endl;
	boardOut << "\t " << tileArray[2][0].currChar << " | " << tileArray[2][1].currChar << " | " << tileArray[2][2].currChar << endl;
	boardOut << "\tWinner: " << winner << endl;

	boardOut.close();
}

void Board::verifyTile(int& row, int& col)
{//Verifies that the tile at the position chosen by the player is available
	while (!tileArray[row - 1][col - 1].isEmpty)
	{
		cout << "\n\tThat position has already been taken. Choose a different position." << endl;

		cout << " Select a row: ";
		cin >> row;
		checkRowIndex(row);
		cout << " Select a column: ";
		cin >> col;
		checkColIndex(col);
	}
}

void Board::updateTile(int row, int col, int plrNum)
{//Updates the selected tile's availability and sets currChar to the calling player's character

	tileArray[row][col].currChar = players[plrNum]->getChar();
	tileArray[row][col].isEmpty = false;
}

bool Board::checkWinner()
{//Checks if a win condition has been met
	int a;
	int b;
	int seq = 1;

	for (a = 0; a < 3; a++)
	{//Checks the rows for a win condition
		for (b = 0; b < 2; b++)
		{
			if (tileArray[a][b].currChar == ' ')
				break;
			else
				if (tileArray[a][b].currChar == tileArray[a][b + 1].currChar)
					++seq;
				else
					break;
		}

		if (seq == 3)
			return true;
		else
			seq = 1;
	}

	for (a = 0; a < 3; a++)
	{//Checks the columns for a win condition
		for (b = 0; b < 2; b++)
		{
			if (tileArray[b][a].currChar == ' ')
				continue;
			else
				if (tileArray[b][a].currChar == tileArray[b + 1][a].currChar)
					++seq;
				else
					break;
		}

		if (seq == 3)
			return true;
		else
			seq = 1;
	}

	a = 1;
	b = 1;

	//If the center character does not contain an 'X' nor 'O', then the diagonals cannot have a win condition
	if (tileArray[a][b].currChar == ' ')
		return false;
	else
	{
		//Checks the diagonals for a win condition
		if ((tileArray[a][b].currChar == tileArray[a - 1][b - 1].currChar) && (tileArray[a][b].currChar == tileArray[a + 1][b + 1].currChar))
			return true;

		if ((tileArray[a][b].currChar == tileArray[a - 1][b + 1].currChar) && (tileArray[a][b].currChar == tileArray[a + 1][b - 1].currChar))
			return true;
	}

	return false;
}