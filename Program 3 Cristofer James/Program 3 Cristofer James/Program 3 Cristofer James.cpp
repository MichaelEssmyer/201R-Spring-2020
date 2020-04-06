//Cristofer James
//CS201R
//Program 3
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void menu();
void readData(int idNum[], string firstName[], string lastName[], string cityName[], string stateAbbr[], double gpa[]);
int getInput();
void validateInput(int& input);
void selectionHandling(int selection, int idNum[], string firstName[], string lastName[], string cityName[], string state[], double gpa[]);
void display_Info(int ID[], string first[], string last[], string city[], string state[], double GPA[]);
void display(int ID[], string first[], string last[], string city[], string state[], double GPA[]);
void count_city(string city[], string state[]);

bool isExit = false;
const int ARRAY_SIZE = 10;

int main()
{
	int studentID[ARRAY_SIZE];
	string firstName[ARRAY_SIZE];
	string lastName[ARRAY_SIZE];
	string cityName[ARRAY_SIZE];
	string state[ARRAY_SIZE];
	double studentGPA[ARRAY_SIZE];

	readData(studentID, firstName, lastName, cityName, state, studentGPA);

	do
	{//Calls selectionHandling() until isExit is set to true
		selectionHandling(getInput(), studentID, firstName, lastName, cityName, state, studentGPA);

	} while (!isExit);
	
	return 0;
}

void menu()
{//Displays the menu so the user knows the options they can choose from and how to quit the program
	cout << "\nWelcome to Student Center" << endl;
	cout << "1- Display Student Info" << endl;
	cout << "2- Display Student Info sorted by City" << endl;
	cout << "3- Display Student Info sorted by City and total number of students in each city" << endl;
	cout << "4- Exit" << endl;
	cout << "Please choose an option: ";
}

void readData(int idNum[], string firstName[], string lastName[], string cityName[], string state[], double gpa[])
{//Reads data from Student_Info.txt and populates the appropriate arrays
	ifstream inFile;
	int arrayPos = 0;

	inFile.open("Student_Info.txt");

	while ((arrayPos < ARRAY_SIZE) && (!inFile.eof()))
	{
		inFile >> idNum[arrayPos] >> firstName[arrayPos] >> lastName[arrayPos] >> cityName[arrayPos] >> state[arrayPos] >> gpa[arrayPos];
		arrayPos++;
	}

	if (!inFile.eof())
	{
		cout << "Error reading file. Program will now exit." << endl;
		isExit = true;
	}

	inFile.close();
}


int getInput()
{//Gets input from the user for option selection
	int userInput;
	menu();
	cin >> userInput;
	validateInput(userInput);

	return userInput;
}

void validateInput(int& input)
{//Takes the user input returned by getInput() and validates the user's entry
	while ((input < 1) || (input > 4))
	{
		cout << "\n\tThat input is invalid." << endl << endl;
		menu();
		cin >> input;
	}
}

void selectionHandling(int selection, int idNum[], string firstName[], string lastName[], string cityName[], string state[], double gpa[])
{//Performs appropriate function calls based on user input
	switch (selection)
	{
	case 1:
	{
		display_Info(idNum, firstName, lastName, cityName, state, gpa);
		break;
	}
	case 2:
	{
		display(idNum, firstName, lastName, cityName, state, gpa);
		break;
	}
	case 3:
	{
		display(idNum, firstName, lastName, cityName, state, gpa);
		count_city(cityName, state);
		break;
	}
	case 4:
	{
		cout << "\nGoodbye" << endl;
		isExit = true;
		break;
	}
	default:
	{
		cout << "\n\tAn error was encoutnered. The program will now exit." << endl;
		isExit = true;
		break;
	}
	}
}

void display_Info(int ID[], string first[], string last[], string city[], string state[], double GPA[])
{//Displays the contents of the parallel arrays
	for (int a = 0; a < ARRAY_SIZE; a++)
	{
		cout << setw(5) << ID[a];
		cout << setw(20) << first[a];
		cout << setw(20) << last[a];
		cout << setw(20) << city[a];
		cout << setw(20) << state[a];
		cout << setw(20) << GPA[a] << endl;
	}
}

void display(int ID[], string first[], string last[], string city[], string state[], double GPA[])
{//Displays the array sorted by city
	string cityCopy[ARRAY_SIZE];
	int idx;

	for (int a = 0; a < ARRAY_SIZE; a++)
	{//Copy city[] array to cityCopy[] array
		cityCopy[a] = city[a];
	}

	for (int a = 0; a < ARRAY_SIZE - 1; a++)
	{//Gets the first alphebetical entry in the cityCopy array
		idx = a;

		for (int b = 1; b < ARRAY_SIZE; b++)
		{
			if (cityCopy[b].compare(cityCopy[idx]) <= 0)
			{
				idx = b;
			}
		}

		//Outputs the lowest alphabetical entry after the inner for loop finds it
		cout << setw(5) << ID[idx];
		cout << setw(20) << first[idx];
		cout << setw(20) << last[idx];
		cout << setw(20) << city[idx];
		cout << setw(20) << state[idx];
		cout << setw(20) << GPA[idx] << endl;
		//Sets the value that was just output to a large enough string so it is not output multiple times
		cityCopy[idx] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	}
}

void count_city(string city[], string state[])
{//Counts how many times each city appears within the city array
	int count = 1;
	string cityCopy[ARRAY_SIZE];

	for (int a = 0; a < ARRAY_SIZE; a++)
	{//Copy city[] array to cityCopy[] array
		cityCopy[a] = city[a];
	}

	for (int a = ARRAY_SIZE - 1; a >= 0; a--)
	{//Sort cityCopy[] array ascending alphabetically
		for (int b = 1; b < ARRAY_SIZE; b++)
		{
			if (cityCopy[b - 1] >= cityCopy[b])
			{
				string tempStr = cityCopy[b];
				cityCopy[b] = cityCopy[b - 1];
				cityCopy[b - 1] = tempStr;
			}
		}
	}

	for (int a = 1; a < ARRAY_SIZE; a++)
	{//Counts the instances of each city in the sorted cityCopy[] array
		if (cityCopy[a] == cityCopy[a - 1])
		{
			count++;
		}
		else
		{
			cout << setw(20) << "*****We have " << count << " students from " << cityCopy[a - 1] << " this year*****" << endl;
			count = 1;
		}
	}
}