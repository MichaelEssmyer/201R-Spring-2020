//
//  Player.hpp
//  Program 4 Conner Keiter
//
//  Created by Conner Keiter on 3/17/20.
//  Copyright © 2020 Conner Keiter. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Player{
public:
    Player();
    Player(string name,char mark);
    void SetName(string name);
    string GetName();
    void SetMark(char mark);
    char GetMark();
    bool GetIsWinner();
    void SetIsWinner();
private:
    string playerName;
    char playerMark;
    bool isWinner;
};
#endif /* Player_hpp */
