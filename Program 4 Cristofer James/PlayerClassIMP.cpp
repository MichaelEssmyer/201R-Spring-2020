#include <iostream>
#include <string>
#include "PlayerClass.h"
using namespace std;

Player::Player()
{//Default constructor for Player objects
	this->plrName = "NoName";
	this->plrChar = '?';
}

void Player::setName(string plrName)
{//Sets the player's game name
	this->plrName = plrName;
}

string Player::getName()
{
	return this->plrName;
}

void Player::setChar(char plrChar)
{
	this->plrChar = plrChar;
}

char Player::getChar()
{
	return this->plrChar;
}