//Cristofer James
//Spring 2020 Spring 2020
//Program 6
#include <iostream>

using namespace std;

bool tokenRecursion(int& tokens, const int goal, const int turns);

int main()
{
	int curr_tokens = 13;
	int goal_tokens;
	int turn_limit;
	char replay = 'N';

	do
	{
		system("cls");
		cout << "Enter the token goal you want to reach: ";
		cin >> goal_tokens;
		cout << "Enter the number of turns: ";
		cin >> turn_limit;

		cout << "\n__Starting Conditions__" << endl;
		cout << "   Initial Tokens: " << curr_tokens << endl;
		cout << "   Token Goal: " << goal_tokens << endl;
		cout << "   Turn Limit: " << turn_limit << endl;

		cout << "\nSearching for a solution within " << turn_limit << " turn(s)..." << endl;
		tokenRecursion(curr_tokens, goal_tokens, turn_limit);

		cout << endl;
		cout << "Would you like to try again[Y/N]: ";
		cin >> replay;

	} while (toupper(replay) == 'Y');

	return 0;
}

bool tokenRecursion(int& tokens, const int goal, const int turns)
{//Recursively finds a solution, or lack thereof, for the entered conditions
	int turns_remaining = turns;

	if (turns_remaining <= 0)
	{//If all turns have been used, output the failure message and return false
		cout << "No solution was found within the turn limit." << endl;
		return false;
	}
	else
		if (tokens == goal)
		{//If a solution was found, ouput the success message and return true
			cout << "A solution was found with " << turns_remaining << " turn(s) remaining." << endl;
			return true;
		}

	if ((tokens % 2) == 0)
	{//Set the current tokens to half of the current tokens, and inform the user of the operation and new amount of tokens
		tokens /= 2;
		cout << "Dividing tokens by 2; There are now " << tokens << " tokens." << endl;
	}
	else
	{//Set the current tokens to the current tokens plus 25, and inform the user of the operation and new amount of tokens
		tokens += 25;
		cout << "Adding 25 tokens; There are now " << tokens << " tokens." << endl;
	}
	//Recursively calls itself with the new number of turns remaining
	return tokenRecursion(tokens, goal, turns_remaining - 1);
}