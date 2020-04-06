//
//  Player.cpp
//  Program 4 Conner Keiter
//
//  Created by Conner Keiter on 3/17/20.
//  Copyright © 2020 Conner Keiter. All rights reserved.
//

#include "Player.hpp"
using namespace std;

Player::Player(){
    isWinner = false;
}
//parametric constructor for if name and mark is passed to class def
Player::Player(string name,char mark){
    SetName(name);
    SetMark(mark);
    isWinner = false;
}
//each of the 3 components to a player object has getters and setters as follows
void Player::SetName(string name){
    this -> playerName = name;
}
string Player::GetName() {
    return playerName;
}
void Player::SetMark(char mark){
    this -> playerMark = mark;
}
char Player::GetMark(){
    return playerMark;
}

bool Player::GetIsWinner(){
    return isWinner;
}
void Player::SetIsWinner(){
    isWinner = true;
}
