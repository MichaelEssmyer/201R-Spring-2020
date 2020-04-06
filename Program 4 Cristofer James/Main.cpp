//Cristofer James
//CS201R Spring 2020
//Program 4
#include <iostream>
#include "BoardClass.h"
using namespace std;

void newGame(bool& quit);
void validateInput(char& input);

int main()
{
	bool quitCmnd = false;

	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Board* board = nullptr;

	do
	{
		board = new Board(p1, p2);
		board->runGame();

		delete board;
		board = nullptr;
		newGame(quitCmnd);

	} while (!quitCmnd);

	cout << "\t\tClosing Program" << endl << endl;

	return 0;
}

void newGame(bool& quit)
{//Prompts the user to see if they want to play another game
	char userInput;

	cin.ignore(INT_MAX, '\n');
	cout << "Would you like to play again(Y|N): ";
	cin.get(userInput);
	validateInput(userInput);

	if (toupper(userInput) != 'Y')
		quit = true;

	cin.ignore(INT_MAX, '\n');
	system("cls");
}

void validateInput(char& input)
{//Validates the user's input
	while ((toupper(input) != 'Y') && (toupper(input) != 'N'))
	{
		cout << endl << endl;
		cout << "Please enter a valid choice(Y|N): ";
		cin.get(input);
	}
	cout << endl << endl;
}