//
//  board.hpp
//  Program 4 Conner Keiter
//
//  Created by Conner Keiter on 3/8/20.
//  Copyright © 2020 Conner Keiter. All rights reserved.
//


#pragma once
#include <iostream>
#include <string>
#include "tile.hpp"
#include "Player.hpp"
using namespace std;

class Board {
public:
    Board();
    Board(Player* p1, Player* p2);
    bool checkTile(int location);
    bool checkWinner();
    void RunGame();
    void TakeTurn(Player turnPlayer);
    void PrintBoard();
    void SaveBoard(ostream& outfile);
private:
    Tile the_board[9];
    Player the_players[2];
};



