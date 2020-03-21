#define RUN 1
#define TEST 0

#if RUN
#include "common.h"





int main() {

	Player* Player1;
	Player* Player2;
	Board* board;
	
	std::string temp_name;
	std::cout << "Enter Player 1's name: " << std::endl;
	std::getline(std::cin, temp_name);
	Player1 = new Player(temp_name);
	std::cout << "Enter Player 2's name: " << std::endl;
	std::getline(std::cin, temp_name);
	Player2 = new Player(temp_name);
	
	
	
	/* The game as requested */
	
	board= new Board(Player1, Player2);
	board->PlayGame();
	
	
	
	/*Just Deleting data and nulling pointers*/
	
	delete board;
	board = nullptr;

	/*Player data was delete in Destructor of Board :# */
	Player1 = nullptr;
	Player2 = nullptr;
	

}

#endif 