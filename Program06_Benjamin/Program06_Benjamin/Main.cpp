#include <iostream>
using namespace std;


int Rungame(int init, int target, int turn, int substract,int stable)
{


	if (substract != stable)
	{
		if (init == target)
		{
			return stable - substract;
		}
		if (init  % 2 == 1)
		{
			
			init += 25;
			cout << "Adding 25, you get " << init << " tokens." << endl;
			Rungame(init, target, turn-1, substract+1,stable);
		}
		
		else if (init%2==0)
		{
			init = init / 2;
			cout << "Reducing by half, you get " << init << " tokens." << endl;
			Rungame(init, target, turn - 1, substract + 1, stable);
			

		}
	}
	else
	{
		if (init == target)
		{
			return stable - substract;
		}
		return -1;

	}
	
	
}


int main()
{
	



	while (true)
	{
	int token_target, turn, ori_token = 13;
	string choice;
	int return_val;
	int number = 0;
	int keep_ori_turn;
			
			cout << "The initial token is 13";
			cout << endl << "Enter the number of tokens you want to reach: " << endl;
			cin >> token_target;
			cout << "What is the number of turn: " << endl;
			cin >> turn;
			cout << "Searching for solution within " << turn << " turn(s)..." << endl;
			keep_ori_turn = turn;
			return_val = Rungame(ori_token, token_target, turn, number, keep_ori_turn);

			if (return_val >= 0)
			{
				cout << endl << "Solution found with " << return_val << " turn(s) remaining." << endl;
			}
			else
			{
				cout << "Sorry, solution wasn't found within allotted turns. " << endl;
			}


			cout << "Would you like to play again? [Y/N]" << endl;
			cin >> choice;
			
			while (choice != "y" && choice != "Y" && choice != "n" && choice != "N")
			{
				cout << "enter again" << endl;
				cin >> choice;
				
			}
			if (choice == "y" || choice == "Y")
			{
				continue; 
			}
			else if (choice == "n" || choice == "N")
			{
			cout << "Thanks for playing!" << endl;
			break;
			}
		}
		
	system("pause");
	return 0;
}