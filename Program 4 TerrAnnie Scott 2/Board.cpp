#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Player.h"
using namespace std;






struct Tile {
	string tile;
	bool CheckTitle(Tile myArr[], int index) {//Checks title availability
		if (myArr[index].tile !=" ") {
			return false;

		}
		return true;
	}
	bool CheckWinner(Tile myArr[], string symbol) {//Checks to see if there is winner 
		if (myArr[0].tile == symbol && myArr[1].tile == symbol && myArr[2].tile == symbol) {
			return true;
		}
		else if (myArr[3].tile == symbol && myArr[4].tile == symbol && myArr[5].tile == symbol) {
			return true;
		}
		else if (myArr[6].tile == symbol && myArr[7].tile == symbol && myArr[8].tile == symbol) {
			return true;
		}
		else if (myArr[0].tile == symbol && myArr[3].tile == symbol && myArr[6].tile == symbol) {
			return true;
		}
		else if (myArr[1].tile == symbol && myArr[4].tile == symbol && myArr[7].tile == symbol) {
			return true;
		}
		else if (myArr[2].tile == symbol && myArr[5].tile == symbol && myArr[8].tile == symbol) {
			return true;
		}
		else if (myArr[0].tile == symbol && myArr[4].tile == symbol && myArr[8].tile == symbol) {
			return true;
		}
		else if (myArr[2].tile == symbol && myArr[4].tile == symbol && myArr[6].tile == symbol) {
			return true;
		}
		else {
			return false;
		}
		
	}
	


};

class Board {
	public:
		void createBoard();//Creates the Board, prints a blank board
		void PrintBoard();//Prints the Board 
		void playerTurn();//What runs the game
		Tile board[9];//The board tiles
		Player names[2];//Get Players 
		void GetName();//GetName() of the Players;
		void Output(int Round);//Outputs to the file
		int PlayAgain();//Ask the user if they want to play again
	
		


		
		
		
		


		
	


	
};

int Board::PlayAgain() {//Checks to see if the user would like to play again returns -1 if yes and 1 if no
	bool play = true;
	string userChoice;

	while (play == true) {
		cout << "Would you like to play again? Y for Yes and N for no" << endl;
		cin >> userChoice;
		if (userChoice == "y" || userChoice == "Y") {
			play = false;
			return -1;



		}

		if (userChoice == "N" || userChoice == "n") {
			
			cout << endl;
			cout << "Thanks for playing Bye!" << endl;
			cout << endl;
			play = false;
			return 1;

		}
		else {
			cout << "Please Enter Something Valid" << endl;
			cout << endl;
			continue;
		}
	}


}
void Board::Output(int Round) {//Outputs to the file
	Tile check;
	Board play;

	ofstream fout;
	fout.open("output.txt", ios::app);

	if (Round == 0) {//In order to see if there's a new game to the file output's only on the first round
		fout << endl;
		fout << "New Game:" << endl;
		fout << endl;
		fout << names[0].GetPlayerName() << ": " << names[0].GetPlayerSymbol() << "\t" << names[1].GetPlayerName() << ": " << names[1].GetPlayerSymbol() << endl;
		fout << endl;
		fout << "------------------------------------------------" << endl;
		

	}
	
	
		

	
	if (check.CheckWinner(board, names[0].GetPlayerSymbol())) {
		fout << names[0].GetPlayerName() << " W " << names[1].GetPlayerName() << " L " << endl;//Checks to see if the winner ot if its a tie if so prints an L Or W or T next to the name
	}
	else if (check.CheckWinner(board, names[1].GetPlayerSymbol())) {
		fout << names[0].GetPlayerName() << " L " << names[1].GetPlayerName() << " W " << endl;
	}
	else{
		fout << names[0].GetPlayerName() << " T " << names[1].GetPlayerName() << " T " << endl;

	}

	fout << "  " << board[0].tile << " | " << board[1].tile << " | " << board[2].tile << endl;
	fout  << " ___" << "|" << "___" << "|" << "___" << endl;
	fout << "  " << board[3].tile << " | " << board[4].tile << " | " << board[5].tile << endl;
	fout  << " ___" << "|" << "___" << "|" << "___" << endl;
	fout << "  " << board[6].tile << " | " << board[7].tile << " | " << board[8].tile << endl;
	fout.close();


}
void Board::GetName() {//Get the names of everything and the symbol of everything
	Player player1;//Player 1
	Player player2;//Player 2
	string name;//Name of player1;
	string symbol;//Naoe of Player 2
	bool cnt = true;//Lets the while loop run
	string name1;// name of other player
	string symbol2;//Symbol of player2
	string initial;//Initial or last name of other player






	
	while (cnt == true) {// Allows everything to loop
		cout << "Enter Player1 name, enter -1 for the default name(player 1)--> ";
		cin >> name;
		if (name == "-1") {
			name = "Player1";
			cnt = false;
		}
		cnt = false;
	}
	cout << endl;
	cnt = true;
	while (cnt == true) {
		cout << endl;
		cout << "Enter a Symbol, if -1 is entered default to X --> ";
		cin >> symbol;
		if (symbol == "-1") {
			symbol = "X";
			cnt = false;

		}
		if (symbol.size() > 1) {
			cout << "Please enter a symbol that is only 1 character" << endl;
			cout << endl;

			continue;
		}
		cnt = false;
		

	}
	player1.SetPlayerNameAndSymbol(name, symbol);
	cnt = true;
	cout << endl;
	while (cnt == true) {//If players have the same name will ask the other player to enter an initial or their last name 
		cout << "Enter Player2 name, enter -1 for the default name(Player2)--> ";
		cin >> name1;
		if (name1 == "-1") {//If the user somehow enters nothing. They Will get a default name
			name1 = "Player2";
			cnt = false;
		}
		if (name1 == name) {
			cout << endl;

			cout << "What is your last initial or last Name --> ";
			cin >> initial;
			name1 = name1 + " " + initial;
			cnt = false;

		}
		cnt = false;
	}
	cnt = true;
	while (cnt == true) {//Gets user symbol and name for player 2 if they have the same symbol asks for them to go again entering -1 will give a default symbol
		cout << endl;
		cout << "Enter a Symbol, if -1 is entered default to O --> ";
		cin >> symbol2;
		if (symbol2 == "-1") {
			symbol2 = "O";
			cnt = false;

		}
		if (symbol2.size() > 1) {
			cout << endl;
			cout << "Please enter a symbol that is only 1 character" << endl;
			cout << endl;
			continue;
		}
		if (symbol2 == symbol) {
			cout << "Please enter a symbol that is not the same as the other players" << endl;
			cout << endl;
			continue;
		}
		cnt = false;


	}
	cnt = true;
	player2.SetPlayerNameAndSymbol(name1, symbol2);
	names[0] = player1;
	names[1] = player2;
	


		

}
void Board::createBoard() {//Creates the board by puting in a space into each part
	board[0].tile = " ";
	board[1].tile = " ";
	board[2].tile = " ";
	board[3].tile = " ";
	board[4].tile = " ";
	board[5].tile = " ";
	board[6].tile = " ";
	board[7].tile = " ";
	board[8].tile = " ";



}
void Board::PrintBoard() {//Prints the board 
	cout << endl;
	cout << "  " << board[0].tile << " | " << board[1].tile << " | " << board[2].tile << endl;
	cout << " ___" << "|" << "___" << "|" << "___" << endl;
	cout << "  " << board[3].tile << " | " << board[4].tile << " | " << board[5].tile << endl;
	cout << " ___" << "|" << "___" << "|" << "___" << endl;
	cout << "  " << board[6].tile << " | " << board[7].tile << " | " << board[8].tile << endl;
	cout << endl;
	


}
void Board::playerTurn() {
	int Round = 0;//Counts how many Rounds have gone
	bool play = false;//Sees if the want to play again
	int RoundCnt = 0;//Counts how many Rounds in each iniduvial game
	int row;//Gets row
	int column;//Gets Columns
	int x;// Gets were we need to put the variable explained later
	Tile check;//So we can use tile functions
	bool cnt = true;// WOrds for the loop
	bool columnCheck = false;//For a loop to make sure all errors are handled
	int  i = 0;//Index of list can only be 1 and 0
	int userChoice;//If the user wants to play again will get this number from a function
	
	while ( RoundCnt < 9) {//If it exceeds this points then there is a tie

		
		while (cnt == true) {
			cout << names[i].GetPlayerName() << "'s turn" << endl;//Gets the chosen players name
			try {
				cout << "Enter Row: ";
				cin >> row;
				cout << endl;//If they enter something thats not a number.
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw runtime_error("Please enter a number\n");
				}

			}
			catch (runtime_error &row){
				cout << row.what();
				cout << endl;
				continue;

			}
			
			if (row < 1) {
				cout << "Please enter a number between 1 and 3" << endl;
				continue;
			}
			if (row >3){
				cout << "Please enter a number between 1 and 3" << endl;
				continue;

			}
			while (columnCheck == false) {
				try {
					cout << "Enter Column: ";//Error Handling just in case the user enters a word and not a letter 
					cin >> column;
					cout << endl;
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						throw runtime_error("Please enter a number\n");
					}

				}
				catch (runtime_error & column) {
					cout << column.what();
					cout << endl;
					continue;
				}
				
				if (column < 1) {
					cout << "Please enter a number between 1 and 3" << endl;//Error just in case the user enters something larger than we can get
					continue;

				}
				if (column > 3) {
					cout << "Please enter a number between 1 and 3" << endl;
					continue;
				}
				else {
					columnCheck = true;
				}
			}
			row = row - 1;
			column = column - 1;
			if (row == 0) { // TO get index of tile from the user row and column choice.
				x = row + column;
			}
			else if (row == 1) {
				x = row + 2 + column;

			}
			else {
				x = row + 4 + column;

			}
			if (check.CheckTitle(board, x)) {//Check to see if the tile is available if yes then continue, if not ask for them to enter in again
				board[x].tile = names[i].GetPlayerSymbol();//Set the title with the player chosen symbol
				columnCheck = false;
				PrintBoard();//Print out the board
				if (check.CheckWinner(board, names[i].GetPlayerSymbol())) {//Checks to see if there is a winner if yes someone has one and play  - true
					cout << names[i].GetPlayerName() << " has won!" << endl;
					play = true;//So we can see if they want to play again
					


				}

				RoundCnt += 1;//Add one to round count if even then i =0 if odd then i=1 so we can get the two elements in the array
				if (RoundCnt % 2 == 0) {
					i = 0;
				}
				else {
					i = 1;
				}

				if (RoundCnt == 9 && play == false) {// If RoundCnt gets to 9 then there is a tie because we didn't find a winner
					cout << "There has been a tie" << endl;
					play = true;
					
				}
				
				if (play == true) {
					userChoice = PlayAgain();
					if (userChoice == -1) {//Reset variables 
						Output(Round);//Output to the file, round is needed so if Round ==0 then we can get a special output for beginning rounds.
						Round += 1;
						createBoard();
						PrintBoard();
						play = false;
						RoundCnt = 0; 
						i = 0;
						continue;


					}
					if (userChoice == 1) {//If one break out of the loop 
						Output(Round);
						RoundCnt = 10;
						break;

					}

				}
				
				
				
			}
			else {
				cout << "Tile is Not Available please try again." << endl;
				columnCheck = false;
				continue;
			}
			
			
			
		}
		
	}
	

}
	