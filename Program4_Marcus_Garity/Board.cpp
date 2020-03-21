#include "Board.h"

#include <ios>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>


Board::Board(Player* Player1, Player* Player2) {
	Player_array[0] = Player1;
	Player_array[1] = Player2;
	Player_array[0]->mark = 'X';
	Player_array[1]->mark = 'O';
	for (int row = 1; row <= 3; row++) {
		for (int col = 1; col <= 3; col++) {

			this -> Tile_array[((row + 1) * (row - 1)) + (col - 1) - (row / 3 * 2)] = new Tile(row, col);


		}
	}


}

Board::~Board() {
	delete Player_array[0];
	delete Player_array[1];
	Player_array[0] = nullptr;
	Player_array[1] = nullptr;
}


void Board::PlayGame(){
	std::string userInput;
	bool nowin = true;
	bool invalid = true;
	int userRow;
	int userCol;
	int turns;
	do {
		ClearBoard();
		nowin = true;
		turns = 0;
		Player_array[0]->win = false;
		Player_array[1]->win = false;
		do {


			for (int i = 0; i < 2; i++) {
				DisplayBoard();
				turns++;

				std::cout << Player_array[i]->name<<"'s turn" << std::endl;
				invalid = true;
				while (invalid) {
					invalid = false;

					try {
						std::cout << "Choose Row ==> " << std::endl;
						std::cin >> userRow;

						if (std::cin.fail()) {
							//clear error state
							std::cin.clear();
							//Ignore cahracter in stream until newline
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							throw std::runtime_error("Invalid input recieved, you must enter an Integer number.");

						}

						if (userRow < 1 || userRow>3)
							throw std::runtime_error("Must Enter Integer greater than or equal to 1 and less than or equal to 3");

						std::cout << "Choose Collumn ==> " << std::endl;
						std::cin >> userCol;

						if (std::cin.fail()) {
							//clear error state
							std::cin.clear();
							//Ignore cahracter in stream until newline
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							throw std::runtime_error("Invalid input recieved, you must enter an Integer number.");

						}

						if (userCol < 1 || userCol>3)
							throw std::runtime_error("Must Enter Integer greater than or equal to 1 and less than or equal to 3");



						if (!this->Tile_array[((userRow + 1) * (userRow - 1)) + (userCol - 1) - (userRow / 3 * 2)]->available)
							throw std::runtime_error("Tile not available, choose another tile");


						this->Tile_array[((userRow + 1) * (userRow - 1)) + (userCol - 1) - (userRow / 3 * 2)]->mark = this->Player_array[i]->mark;
						this->Tile_array[((userRow + 1) * (userRow - 1)) + (userCol - 1) - (userRow / 3 * 2)]->available = false;


					}


					catch (std::runtime_error & excpt) {
						std::cout << excpt.what() << std::endl;
						invalid = true;

					}









				}



				if (CheckWin(Player_array[i]->mark)) {

					std::cout <<"***************"<< Player_array[i]->name << " wins!******************" << std::endl;
					Player_array[i]->win = true;
					nowin = false;
					PrintFile();

					break;
				}
				if (turns == 9) {
					std::cout << "***********Tie Game!***********" << std::endl;
					nowin = false;
					PrintFile();

					break;
				}


				


			}



		} while (nowin);

		std::cout << "Do you want to play again? Y/N" <<std:: endl;
		std::cin.ignore();
		std::getline(std::cin, userInput);

		
		
	} while (userInput != "N");
}

void Board::DisplayBoard() {

	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ') << std::setw(4) << Tile_array[0]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[1]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[2]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << '_' << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ') << std::setw(4) << Tile_array[3]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[4]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[5]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << '_' << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	std::cout << std::setfill(' ') << std::setw(4) << Tile_array[6]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[7]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[8]->mark << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;

}

bool Board::CheckWin(char playerMark) {
	
	if (CheckRightDiagonal(playerMark))
		return true;
	if (CheckLeftDiagonal(playerMark))
		return true;
	if (CheckHorizontal(playerMark))
		return true;
	if (CheckVertical(playerMark))
		return true;

	return false;
}
bool Board::CheckRightDiagonal(char playerMark) {
	int gameRow;
	int gameCol;
	

	gameRow = 2;
	gameCol = 2;
	if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
		gameRow--;
		gameCol++;
		if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
			gameRow++;
			gameRow++;
			gameCol--;
			gameCol--;
			if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
				return true;
			}
		
		}
	
	}


	return false;



}
bool Board::CheckLeftDiagonal(char playerMark) {
	int gameRow;
	int gameCol;


	gameRow = 2;
	gameCol = 2;
	if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
		gameRow--;
		gameCol--;
		if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
			gameRow++;
			gameRow++;
			gameCol++;
			gameCol++;
			if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
				return true;
			}

		}
	}
		return false;


}
bool Board::CheckHorizontal(char playerMark){
	int gameRow;
	int gameCol;

	for (int i = 1; i <= 3; i++) {

		gameRow = i;
		gameCol = 1;
		if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
			gameCol++;
			if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
				gameCol++;
				if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
					return true;
				}
			}
		}
		
	}

	return false;

}
bool Board::CheckVertical(char playerMark){

	int gameRow;
	int gameCol;

	for (int i = 1; i <= 3; i++) {

		gameRow = 1;
		gameCol = i;
		if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
			gameRow++;
			if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
				gameRow++;
				if (Tile_array[((gameRow + 1) * (gameRow - 1)) + (gameCol - 1) - (gameRow / 3 * 2)]->mark == playerMark) {
					return true;
				}
			}
		}

	}

	return false;





}

void Board::ClearBoard() {

	for (int row = 1; row <= 3; row++) {
		for (int col = 1; col <= 3; col++) {

			delete this->Tile_array[((row + 1) * (row - 1)) + (col - 1) - (row / 3 * 2)];
			this->Tile_array[((row + 1) * (row - 1)) + (col - 1) - (row / 3 * 2)] = nullptr;


		}
	}


	for (int row = 1; row <= 3; row++) {
		for (int col = 1; col <= 3; col++) {

			this->Tile_array[((row + 1) * (row - 1)) + (col - 1) - (row / 3 * 2)] = new Tile(row, col);


		}
	}


}


void Board::PrintFile() {

	std::ofstream fout("Record.txt", std::ios_base::app);
	if (Player_array[0]->win)
		fout << Player_array[0]->name << " W " << Player_array[1]->name << " L " << std::endl;
	if (Player_array[1]->win)
		fout << Player_array[0]->name << " L " << Player_array[1]->name << " W " << std::endl;
	if (!Player_array[1]->win && !Player_array[0]->win)
		fout << Player_array[0]->name << " T " << Player_array[1]->name << " T " << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	fout << std::setfill(' ') << std::setw(4) << Tile_array[0]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[1]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[2]->mark << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	fout << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << '_' << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	fout << std::setfill(' ') << std::setw(4) << Tile_array[3]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[4]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[5]->mark << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	fout << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << std::setfill('_') << '_' << "||" << std::setw(6) << '_' << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;
	fout << std::setfill(' ') << std::setw(4) << Tile_array[6]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[7]->mark << std::setw(4) << "||" << std::setw(4) << Tile_array[8]->mark << std::endl;
	fout << std::setfill(' ') << std::setw(8) << "||" << std::setw(8) << "||" << std::setw(4) << std::endl;


	fout.close();


}