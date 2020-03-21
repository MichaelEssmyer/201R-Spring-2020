#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player 
{
	public:
		Player();
		Player(string username, string userCharr);
		
		string getName() ;
		string getChar();
		

	private:
		string name;
		string Char;
};





#endif
