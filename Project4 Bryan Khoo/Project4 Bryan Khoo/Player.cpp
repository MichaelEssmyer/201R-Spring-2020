#include "Player.h"
#include <sstream>
#include <string>
#include <stdexcept>
//class Player constructor that sets the current object's playerSymbol with the playerSymbol passed in
Player::Player(char playerSymbol) {
	this->playerSymbol = playerSymbol;
}
//class Player method that receives input as name
void Player::AskName() {
	std::string name;
	getline(std::cin, name);
	playerName = name;
}
//class Player method that ask for user input for position the player wishes to place their symbol
void Player::AskTile() {
	//have an array that stores row and column. this allows implementation of a loop as one question can be asked, just switch between the array for desired question
	std::string coordinates[2] = { "row", "column" };
	//declare string stream and string variable
	std::string userInput;
	//reason why declare string stream is to detect invalid input 
	std::istringstream inSS;
	int position;
	for (int i = 0; i < 2; i++) {
		//ask user for input
		std::cout << "Enter the " << coordinates[i] << " (1 - 3): ";
		//collect line and input it into position, if datatype does not match, there will be an error
		getline(std::cin, userInput);
		inSS.clear();
		inSS.str(userInput);
		inSS >> position;
		//if failed to output data into position, throw an error with the reason why it failed
		if (inSS.fail()) {
			throw std::runtime_error("Please input an integer");
		}
		//ensure that user input is only within range 1 to 3, if it is not, throw error with explanation on the range
		if (position < 1 || position > 3){
			throw std::runtime_error("Please enter within range 1 - 3");
		}
		//since user will input 1 to 3, minus 1 from the input to be able to store into array as array's range is 0 - 2.
		if (i == 0) {
			playerTile.posX = position - 1;
		}
		else {
			playerTile.posY = position - 1;
		}
	}
}

//below all the methods are just getters and setters. 
//this is to get playerTile that contants row and column position
Tile Player::GetTile() const {
	return playerTile;
}
//this method is to get player's symbol
char Player::GetSymbol() const {
	return playerSymbol;
}
//this method is to set player's status, whether 'W' or 'T'. the default is 'L'
void Player::SetStatus(char givenStatus) {
	playerStatus = givenStatus;
}
//this method is to get player's name 
std::string Player::GetName() const {
	return playerName;
}
//this method is to get player's status.
char Player::GetStatus() const {
	return playerStatus;
}