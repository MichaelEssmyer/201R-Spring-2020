#pragma once
#include <iostream>
#include <string>
//struct that contains player's desired position. X is row, Y is column
struct Tile {
	int posX;
	int posY;
};
//class Player 
class Player {
public:
	//all class method declarations 
	Player(char playerSymbol);
	void AskTile();
	void AskName();
	void SetStatus(char givenStatus);
	Tile GetTile() const;
	char GetSymbol() const;
	std::string GetName() const;
	char GetStatus() const;
private:
	//declare variables that store player data 
	Tile playerTile;
	std::string playerName;
	char playerSymbol;
	//default player status is L
	char playerStatus = 'L';
};