#include "Board.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



Board::Board(Player* P1, Player* P2)
{
	 this -> the_player[0] = P1;
	 
	 this -> the_player[1] = P2 ;
}
void Board::SaveGame()
{
	ofstream fileout("SaveGameFile.txt", ios::app);
	fileout << "     ||     ||  " << endl;
	fileout << "_ " << The_Board[0][0].mark << " _||_ " << The_Board[0][1].mark << " _||_ " << The_Board[0][2].mark << " _" << endl;
	fileout << "_ " << The_Board[1][0].mark << " _||_ " << The_Board[1][1].mark << " _||_ " << The_Board[1][2].mark << " _" << endl;
	fileout << "_ " << The_Board[2][0].mark << " _||_ " << The_Board[2][1].mark << " _||_ " << The_Board[2][2].mark << " _" << endl;
	fileout << "     ||     ||  " << endl << endl;
	fileout.close();
	
}

int Board:: CheckWinner(string symbol)
{
	int j=0;
	for (int i = 0; i < 3; ++i)
	{
		if (The_Board[i][j].mark == The_Board[i][j + 1].mark && The_Board[i][j + 1].mark == The_Board[i][j + 2].mark && The_Board[i][j + 2].mark == symbol)
		{	
			return 1;
			break;
		}
		if (The_Board[j][i].mark == The_Board[j + 1][i].mark && The_Board[j + 1][i].mark == The_Board[j + 2][i].mark && The_Board[j + 2][i].mark == symbol)
		{			
			return 1;
			break;
		}
		if ((The_Board[0][0].mark == The_Board[1][1].mark) && (The_Board[1][1].mark == The_Board[2][2].mark) && (The_Board[2][2].mark == symbol))
		{
			return 1;
			break;
		}
		if (The_Board[0][2].mark == The_Board[1][1].mark && The_Board[1][1].mark == The_Board[2][0].mark && The_Board[2][0].mark == symbol)
		{
			return 1;
			break;
		}
		
		
	}
	return 0;
}
void Board::ClearFile()
{

	ifstream filein("SaveGameFile.txt");
	if (!filein.is_open())
	{
		cout << "Could not open the file, please check if the file is in right place.";
		return;
	}
	ofstream ofs("SaveGameFile.txt", ios::out | ios::trunc);
}

void Board::PrintBoard()
{
	
	cout << "_ " << The_Board[0][0].mark << " _||_ " << The_Board[0][1].mark << " _||_ " << The_Board[0][2].mark << " _" << endl;
	cout << "_ " << The_Board[1][0].mark << " _||_ " << The_Board[1][1].mark << " _||_ " << The_Board[1][2].mark << " _" << endl;
	cout << "_ " << The_Board[2][0].mark << " _||_ " << The_Board[2][1].mark << " _||_ " << The_Board[2][2].mark << " _" << endl;
	cout << "     ||     ||  " << endl;

}


void Board::rungame()
{
	
	ofstream fileout("SaveGameFile.txt", ios::app);
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			The_Board[a][b].mark = "_";
		}
	}
	PrintBoard();
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
			int col1, col2;
			int row1, row2;
			int check= -1;
			
			while (true)
			{
				cout << the_player[0]->getName() << " enter the row (a number from 1 to 3): " << endl;
				cin >> row1;
				while (row1 < 1 || row1>3)
				{
					cout << "Please enter a valid row (1,2 or 3): " << endl;
					cin >> row1;
				}
				cout << the_player[0]->getName() << " enter the column (a number from 1 to 3): " << endl;
				cin >> col1;
				while (col1 < 1 || col1>3)
				{
					cout << "Please enter a valid column (1,2 or 3): " << endl;
					cin >> col1;
				}
				
				
				int actual_col_1 = col1 - 1;
				int actual_row_1 = row1 - 1;
				if (The_Board[actual_row_1][actual_col_1].available) {
					The_Board[actual_row_1][actual_col_1].mark = the_player[0]->getChar();
					The_Board[actual_row_1][actual_col_1].available = false;
					break;
				}
				else
				{
					cout << "This location has been filled. Please choose another one." << endl << endl;
					
				}
			}
			PrintBoard();
			cout << endl;
			check = CheckWinner(the_player[0]->getChar());
			if (check == 1)
			{
				
				cout << the_player[0]->getName() << " wins" << endl << endl;
			
				fileout << the_player[0]->getName() << " wins" << endl;
				break;
			}
			if (i == 4 && check==0)
			{
				fileout << "Two player tie." << endl;
				cout << "Two players tie" << endl;
				break;
			}
			
			
			cout << endl;
			
			while (true)
			{
		
				
				cout << the_player[1]->getName() << " enter the row (a number from 1 to 3): " << endl;
				cin >> row2;
				while (row2 < 1 || row2>3)
				{
					cout << "Please enter a valid row (1,2 or 3): " << endl;
					cin >> row2;
				}
				cout << endl << the_player[1]->getName() << " enter the column (a number from 1 to 3): " << endl;
				cin >> col2;
				while (col2 < 1 || col2>3)
				{
					cout << "Please enter a valid column (1,2 or 3): " << endl;
					cin >> col2;
				}
				int actual_col_2 = col2 - 1;
				int actual_row_2 = row2 - 1;
				if (The_Board[actual_row_2][actual_col_2].available) {
					The_Board[actual_row_2][actual_col_2].mark = the_player[1]->getChar();
					The_Board[actual_row_2][actual_col_2].available = false;
					break;
				}
				else
				{
					cout << "This location has been filled. Please choose another one." << endl << endl;
					
				}
			}
			
			
			
		
			PrintBoard();
			cout << endl;
			check = CheckWinner(the_player[1]->getChar());
			if (check == 1)
			{
				
				cout << the_player[1]->getName() << " wins" << endl << endl;
				
				fileout << the_player[1]->getName() << " wins" << endl;
				break;
				
			}
			else
			{
				continue;
			}
			fileout.close();
	}
	SaveGame();
	string decision;
	cout << "All games you've played are automatically saved in the file \"SaveGameFile.txt\"." << endl;
	cout << "Do you want to keep or delete (Enter D to delete or any key to keep): "; 
	cin >> decision;
	cout << endl << endl;
	if (decision == "D" || decision== "d")
	{
		cout << "Data cleared." << endl << endl;
		ClearFile();
	}
	
	
}


		
		