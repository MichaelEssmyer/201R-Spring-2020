
// Name: Marcus Garity
// Email: mkgdg4@mail.umkc.edu
// Program: 6
// Created Date: 4/12/2020 
// Due Date: 4/16/2020








#include <iostream>
#include <string>
#include <vector>
#include <cctype>



// is a recursive function that takes in token, token goals, turns, and augmentations
std::string FindPath(int, int, int);
// main game loop of the program.
void GameLoop();

int main() {
	

	GameLoop();

}



void GameLoop() {
	bool valid = true;
	char UserInput;
	std::string garbage;

	while (valid) {

		int token_goal;
		int turns;
		std::cout << "Enter the number of tokens you want to reach:" << std::endl;
		std::cin >> token_goal;
		std::cin.ignore();
		std::cout << "What is the number of turns:" << std::endl;
		std::cin >> turns;
		std::cin.ignore();

		std::cout << "Searching for solution within 10 turn(s)..." << std::endl;
		std::cout << FindPath(token_goal, turns, 13);    
		std::cout << "Would you like to play again? [Y/N]" << std::endl;
		std::cin >> UserInput;
		std::getline(std::cin, garbage);
		if (std::tolower(UserInput) == 'n')
			valid = false;

	}
}






std::string FindPathadd(int token_goal, int turns, int tokens) {

	return "Adding 25, you get " + std::to_string(tokens + 25) + " tokens.\n" + FindPath(token_goal, turns - 1, tokens + 25);


}

std::string FindPathhalf(int token_goal, int turns, int tokens) {

	return "Reducing by half, you get " + std::to_string(tokens / 2) + " tokens.\n" + FindPath(token_goal, turns - 1, tokens / 2);

}



std::string FindPath(int token_goal, int turns, int tokens) {
	std::string (*Branch[2])(int token_goal, int turns, int tokens);
	Branch[0] = &FindPathhalf;
	Branch[1] = &FindPathadd;
	if (tokens == token_goal)
		return " Solution found with 1 turn(s) remaining.\n";
	if (turns == 0)
		return " Sorry, solution wasn't found within allotted turns.\n";
	if (tokens % 2 != 0)
		return (*Branch[1])(token_goal, turns, tokens);
	if (tokens % 2 == 0) 
	{

		for (int i = 0; i < 2; i++) {
		
			return (*Branch[i])(token_goal,turns,tokens);
		
		
		}
		//return "Adding 25, you get " + std::to_string(tokens+25)+" tokens.\n" + FindPath(token_goal, turns - 1, tokens + 25);
		//return "Reducing by half you get" + std::to_string(tokens/2)+" tokens.\n" + FindPath(token_goal, turns - 1, tokens/2);
	}

	

}

