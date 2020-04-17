#include <iostream>

void countingTokens(int token, int desiredToken, int& turns);

int main() {
	int const START_TOKEN = 13;
	int desiredTokens, turns, finalToken;
	char ans; 
	//do-while loop to keep playing game until user prompts to stop playing
	do {
		std::cout << "Enter the number of tokens you want to reach:" << std::endl;
		std::cin >> desiredTokens;
		std::cout << "What is the number of turns?" << std::endl;
		std::cin >> turns;
		std::cout << "Searching for solution within " << turns << " turn(s)." << std::endl;
		countingTokens(START_TOKEN, desiredTokens, turns);
		std::cout << "Would you like to play again? [Y/N]" << std::endl;
		std::cin >> ans;
		ans = toupper(ans);
	} while (ans == 'Y');
	return 0;
}

void countingTokens(int token, int const desiredToken, int& turns) {
	//checks whether user has ran out of turns or not
	if (turns <= 0) {
		std::cout << "Sorry, solution wasn't found within allotted turns." << std::endl;
	}
	else if (token == desiredToken) {
		std::cout << "\nSolution found with " << turns << " turn(s) remaining." << std::endl;
	}
	else if (token%2 == 0) {
		//divide token by 2 if it is even
		token = token / 2;
		std::cout << "Reducing by half, you get " << token << " tokens." << std::endl;
		turns -= 1;
		countingTokens(token, desiredToken, turns);
	}
	else {
		turns -= 1;
		token += 25;
		std::cout << "Adding 25, you get " << token << " tokens." << std::endl;
		//if token is not even, just call recursive function
		countingTokens(token, desiredToken, turns);
	}
}