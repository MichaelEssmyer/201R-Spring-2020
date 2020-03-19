#include <iostream>
#include "Board.h"

int main() {
	//declare and initialize boolean variable that keep tracks whether players want to continue playing or not
	bool keepPlaying = true;
	//declare character variable to store players' answer
	char userAns;
	//create new object board 
	Board board;
	do{
		//call board's RunGame method
		board.RunGame();
		//ask whether player wants to continue playing or not
		std::cout << "Do you want to play again? (type 'n' for no; press any other keys to continue)" << std::endl;
		std::cin >> userAns;
		//set user input to upper case so no matter if user enters 'n' or 'N', we can read it as N. 
		userAns = std::toupper(userAns);
		//if player enters no, set keepPlaying to false to exit the loop
		if (userAns == 'N')
			keepPlaying = false;
		std::cin.ignore();
	} while (keepPlaying);

	return 0;
}