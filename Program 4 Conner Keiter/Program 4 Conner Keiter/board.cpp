
#include <iostream>
#include <string>
#include "board.hpp"
Board::Board(){}
//parametric constructor where the two player objects are passed in and added to the_players
Board::Board(Player* p1, Player* p2){
    the_players[0] = *p1;
    the_players[1] = *p2;
}
//function to check if a specfic tile is available
bool Board::checkTile(int location) {
    return the_board[location].available;
}
//checks all cases of if a winner is found
bool Board::checkWinner(){
    //horizontal checker
    for(int i = 0; i < 8 ; i+=3){
        if((the_board[i].mark==the_board[i+1].mark)&&(the_board[i+1].mark==the_board[i+2].mark) && the_board[i].mark!='_'){
            return true;
        }
    }
    //vertical checker
    for(int i = 0; i < 3 ; i++){
        if((the_board[i].mark==the_board[i+3].mark)&&(the_board[i+3].mark==the_board[i+6].mark)&&the_board[i].mark!='_'){
            return true;
        }
    }
    //1st diag check
    if((the_board[0].mark==the_board[4].mark)&&(the_board[4].mark==the_board[8].mark)&&the_board[0].mark!='_'){
        return true;
    }
    //2nd diag check
    if((the_board[2].mark==the_board[4].mark)&&(the_board[4].mark==the_board[6].mark)&&the_board[2].mark!='_'){
        return true;
    }
    
    return false;
}
//all game logic runs from this sub-main
void Board::RunGame(){
    int count = 0;
    bool winner = false;
    //only allows game to continue for 9 turns (only 9 tiles on board), and no winner yet
    while (count<9&& !winner) {
        //if else block switches turn between players
        if (count%2==0) {
            TakeTurn(the_players[0]);
            winner = checkWinner();
            if (winner) {
                cout << the_players[0].GetName() << " is the winner!!" << endl;
                the_players[0].SetIsWinner();
            }
        }
        else {
            TakeTurn(the_players[1]);
            winner = checkWinner();
            if (winner) {
                cout << the_players[1].GetName() << " is the winner!!" << endl;
                the_players[1].SetIsWinner();
            }
        }
        PrintBoard();
        count++;
    }
    
}
void Board::TakeTurn(Player turnPlayer){
    int row,column,arrayNum;
    //asks for the row and column of tile the player wants to choose, keeps asking until they make a valid selection
    cout << turnPlayer.GetName() << "'s turn" << endl;
    cout << "Enter a row: ";
    cin >> row;
    while (row>3||row<1){
        cout << "You need to choose 1,2, or 3 only" << endl;
        cout << "Enter a row: ";
        cin >> row;
    }
    cout << "Enter a column: ";
    cin >> column;
    while (column>3||column<1){
        cout << "You need to choose 1,2, or 3 only" << endl;
        cout << "Enter a column: ";
        cin >> column;
    }
    //linear algebra equation that converts row and column to appropriate array number
    arrayNum = (3*row)+(column)-4;
    //makes sure that the chosen location is available, if not it continues to ask the user for a new location
    while (!checkTile(arrayNum)){
        cout << "This tile location is already chosen, please choose a different one" << endl;
        cout << "Enter a row: ";
        cin >> row;
        cout << "Enter a column: ";
        cin >> column;
        //linear algebra equation that converts row and column to appropriate array number
        arrayNum = (3*row)+(column)-4;
    }
    the_board[arrayNum].mark = turnPlayer.GetMark();
    the_board[arrayNum].available = false;
    
    
}
void Board::PrintBoard(){
    //prints the board
    cout << "_" << the_board[0].mark << "_||_" << the_board[1].mark << "_||_" << the_board[2].mark << "_" << endl;
    cout << "_" <<the_board[3].mark << "_||_" << the_board[4].mark << "_||_" << the_board[5].mark << "_" << endl;
    cout << " ";
    if(the_board[6].mark!='_') {
        cout << the_board[6].mark;
    }
    else {cout << " ";}
    
    cout << " || ";
    if(the_board[7].mark!='_') {
        cout << the_board[7].mark;
    }
    else {cout << " ";}
    cout << " || " ;
    if(the_board[8].mark!='_') {
        cout << the_board[8].mark;
    }
    else {cout << " ";}
    cout << endl;
}
//writes the board to the file as well as who won
void Board::SaveBoard(ostream& outfile){
    //case of a tie, tie is output to file
    if(!checkWinner()){
        outfile << the_players[0].GetName() << " T " << the_players[1].GetName() << " T" << endl;
    }
    //if p1 wins
    if(the_players[0].GetIsWinner()){
        outfile << the_players[0].GetName() << " W " << the_players[1].GetName() << " L" << endl;
    }
    //if p2 wins
    if(the_players[1].GetIsWinner()){
        outfile << the_players[0].GetName() << " L " << the_players[1].GetName() << " W" << endl;
    }
    outfile << "_" << the_board[0].mark << "_||_" << the_board[1].mark << "_||_" << the_board[2].mark << "_" << endl;
    outfile << "_" <<the_board[3].mark << "_||_" << the_board[4].mark << "_||_" << the_board[5].mark << "_" << endl;
    outfile << " ";
    if(the_board[6].mark!='_') {
        outfile << the_board[6].mark;
    }
    else {outfile << " ";}
    
    outfile << " || ";
    if(the_board[7].mark!='_') {
        outfile << the_board[7].mark;
    }
    else {outfile << " ";}
    outfile << " || " ;
    if(the_board[8].mark!='_') {
        outfile << the_board[8].mark;
    }
    else {outfile << " ";}
    outfile << endl<<endl;
}
