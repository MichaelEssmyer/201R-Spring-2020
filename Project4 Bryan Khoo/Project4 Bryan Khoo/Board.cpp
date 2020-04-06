#include "Board.h"
#include <iomanip>
#include <fstream>

//board class constructor 
Board::Board() {
	//calls SetBoard method that sets all the tiles to default value 
	SetBoard();
}

void Board::SetBoard() {
	//initializes the tile array to have default value as 'N'
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tileArray[i][j] = 'N';
		}
	}
}

//board class method that sets a symbol in the array tile based on user input
void Board::SetTile(char player) {
	tileArray[playerPosition.posX][playerPosition.posY] = player;
}
//board class method that prints out the board into console 
void Board::PrintBoard() {
	int i, j;
	
	for (i = 0; i < 3; i++) {
		std::cout << "   ||   ||   " << std::endl;
		for (j = 0; j < 3; j++) {
			//if the value in array is 'N', just output a space
			if (tileArray[i][j] == 'N') {
				std::cout << "  ";
			}
			//if the value in array is not 'N', output the symbol
			else {
				std::cout << " " << tileArray[i][j];
			}
			//if it is not the third row, print 2 horizontal line to seperate two columns
			//reason why this is needed is to prevent printing a wall at the third column
			if (j != 2) {
				std::cout << " ||";
			}
		}
		std::cout << std::endl;
		//check if it is at the third row, if it is not, print a verticle line
		if (i != 2) {
			std::cout << "___||___||___" << std::endl;
		}
		//if it is the third row, just print out the walls without the verticle lines
		else {
			std::cout << "   ||   ||   " << std::endl;
		}
	}
}
//board class method for checking if the space player intend to place is occupied or not
bool Board::CheckSpace(Tile playerPosition) {
	this->playerPosition = playerPosition;
	//if the value in desired position is not 'N', it means it is occupied 
	if (tileArray[this->playerPosition.posX][this->playerPosition.posY] != 'N') {
		return true;
	}

	return false;
}
//board class method for checking if there is a winner in the game or not 
bool Board::CheckForWinner(char playerSymbol) {
	//declare all necessary variables
	int i, j, k, countRow, countCol;
	//these boolean checks the diagonal parts of the tic-tac-toe. diag1 checks from top left to bottom right; dia2 checks from top right to bottom left
	bool diag1 = (tileArray[0][0] == playerSymbol) && (tileArray[1][1] == playerSymbol) && (tileArray[2][2] == playerSymbol);
	bool diag2 = (tileArray[2][0] == playerSymbol) && (tileArray[1][1] == playerSymbol) && (tileArray[0][2] == playerSymbol);
	//loop to check each row and column whether there is a winner
	//compares symbol that is passed in with the whole tic-tac-toe
	for (i = 0; i < 3; i++) {
		countRow = 0;
		countCol = 0;
		//checks the row 
		for (j = 0; j < 3; j++) {
			if (tileArray[i][j] == playerSymbol) {
				countRow += 1;
			}
		}
		//checks the column 
		for (k = 0; k < 3; k++) {
			if (tileArray[k][i] == playerSymbol) {
				countCol += 1;
			}
		}
		//if the count for row or column is 3, that means that row/column is full of the same symbol
		//thus, there is a winner
		if (countRow == 3 || countCol == 3)
			return true;
	}
	//checks for diagonal tic-tac-toe, see if there is a winner
	if (diag1 || diag2) {
		return true;
	}
	//if there is no winner, return false
	return false;
}
//board class method that runs the game
void Board::RunGame() {
	//declare necessary variables
	bool occupied;
	bool winner = false;
	int count = 0;
	//output to a file named GameRecords, does not override the file
	std::ofstream fout("GameRecords.txt", std::fstream::app);
	//create 2 pointers with different symbol
	players[0] = new Player('X');
	players[1] = new Player('O');
	//loop to ask for each player's name and storing it by calling AskName method 
	for (int x = 0; x < 2; x++) {
		std::cout << "Enter player " << x + 1 << "\'s name:" << std::endl;
		players[x]->AskName();
	}
	//loop to keep asking each player to place their symbol until there is a winner
	do {
		try {
			//ask for positions, if user enters an invalid input, throws an error
			players[count % 2]->AskTile();
		}
		catch (std::runtime_error e) {
			//output that the user had input an invalid input
			//restart to prompt user input again 
			std::cout << e.what() << std::endl;
			continue;
		}
		//check if the position user desires is occupied or not
		occupied = CheckSpace(players[count%2]->GetTile());
		//if not occupied, place player's symbol in that position
		if (occupied == false) {
			SetTile(players[count % 2]->GetSymbol());
		}
		//if space is occupied, output error message and restart loop
		else {
			std::cout << "That space is occupied. Please enter another space." << std::endl;
			continue;
		}
		//check if there is any winner after placing player's symbol in board
		winner = CheckForWinner(players[count % 2]->GetSymbol());
		//call PrintBoard method to output board
		PrintBoard();
		//if it is round 8, meaning there should not be any more space to put a symbol, and there is still no winner
		//set both players' status to 'T' which means tie and quit loop
		if (count == 8 && winner == false) {
			for (int i = 0; i < 2; i++) {
				players[i]->SetStatus('T');
			}
			break;
		}
		//if there is a winner, set the current player's status to 'W' which means winner
		else if (winner) {
			players[count % 2]->SetStatus('W');
		}
		//count is to alternate between player 1 and player 2's turn 
		count++;
	} while (!winner);
	//call board class method SaveGame to output the result to a file
	SaveGame(fout, players);
	//close output file
	fout.close();
	//delete both pointers that were created at the start of this method
	delete players[0];
	delete players[1];
	players[0] = nullptr;
	players[1] = nullptr;
	//reset the board to have default values, removing all the symbols in the board
	SetBoard();
}
//board class method that output's final result to file
void Board::SaveGame(std::ofstream& fout, Player* player[]) {
	//this method is very similar to PrintBoard, except it is "fout" instead of "cout"
	int i, j;
	//this method however, output's player names into file
	for (i = 0; i < 2; i++) {
		fout << player[i]->GetName() << " " << player[i]->GetStatus() << " ";
	}
	fout << std::endl;
	fout << std::endl;
	for (i = 0; i < 3; i++) {
		fout << "   ||   ||   " << std::endl;
		for (j = 0; j < 3; j++) {
			if (tileArray[i][j] == 'N') {
				fout << "  ";
			}
			else {
				fout << " " << tileArray[i][j];
			}
			if (j != 2) {
				fout << " ||";
			}
		}
		fout << std::endl;
		if (i != 2) {
			fout << "___||___||___" << std::endl;
		}
		else {
			fout << "   ||   ||   " << std::endl;
		}
	}
	fout << std::endl;
}