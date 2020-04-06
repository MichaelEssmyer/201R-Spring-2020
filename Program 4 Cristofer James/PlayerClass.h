#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include <string>
using namespace std;

class Player
{
public:
	Player();
	void setName(string plrName);
	string getName();
	void setChar(char plrChar);
	char getChar();

private:
	string plrName;
	char plrChar;
};
#endif