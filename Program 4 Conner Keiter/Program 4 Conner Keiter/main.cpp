//
//  main.cpp
//  Program 4 Conner Keiter
//
//  Created by Conner Keiter on 3/8/20.
//  Copyright © 2020 Conner Keiter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "board.hpp"
#include "tile.hpp"

using namespace std;

int main() {
    Player *p1,*p2;
    p1 = new Player;
    p2 = new Player;
    
    string tempName;
    char tempMark;
    //asks for player info
    cout << "Enter player 1's name: ";
    getline(cin,tempName);
    cout << "Enter player 1's mark (please choose 'X' or 'O'): ";
    cin >> tempMark;
    tempMark = toupper(tempMark);
    while (tempMark != 'X' && tempMark !='O'){
        cout << "Please, only choose 'X' or 'O'" << endl;
        cin >> tempMark;
        tempMark = toupper(tempMark);
    }
    //creates p1 object from info with user input
    p1 = new Player(tempName,tempMark);
    cin.ignore();
    cout << "Enter player 2's name: ";
    getline(cin,tempName);
    if ( p1->GetMark()=='X') {
        cout << "Since " << p1-> GetName() << "'s mark is 'X', your mark is 'O'" << endl;
        tempMark ='O';
    }
    else {
        cout << "Since " << p1-> GetName() << "'s mark is 'O', your mark is 'X'" << endl;
        tempMark ='X';
    }
    //creates p2 object from info with user input
    p2 = new Player(tempName,tempMark);

    
    cout << p1 -> GetName() << "   " << p1->GetMark() << endl;
    cout << p2 -> GetName() << "   " << p2->GetMark() << endl;
    //opens the output file that keeps track of all games, appending new games to create a database of scores
    ofstream outfile;
    outfile.open("BoardResults.txt",ios_base::app);
    char keepPlaying;
    //loops until the users decide to quit
    do{
        Board* theBoard = new Board;
        theBoard = new Board(p1,p2);
        theBoard->RunGame();
        theBoard->SaveBoard(outfile);
        delete theBoard;
        theBoard = nullptr;
        cout << "Do you want to play again? ('q' to quit, any other character to keep playing.)" << endl;
        cin >> keepPlaying;
    } while(keepPlaying!='q');
    //closes the file
    outfile.close();
    //deletes the dynamic objects
    delete p1;
    delete p2;
    p1 = nullptr;
    p2 = nullptr;
    return 0;
}
