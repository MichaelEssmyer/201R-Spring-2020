#ifndef _PLAYER_H
#define _PLAYER_H
#include <string>
struct Player {
	Player();
	Player(std::string);
	std::string name;
	char mark;
	bool win = false;
};



#endif
