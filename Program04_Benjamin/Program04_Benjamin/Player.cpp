
#include "Player.h"
#include <iostream>

using namespace std;



Player::Player()
{
	this->name = "";
	this->Char = "";
}

Player:: Player (string username,  string userCharr)
{
	this->name = username;
	this->Char = userCharr;
}

string Player::getName() 
{
	return name;
}
string Player::getChar()
{
	return Char;
}

