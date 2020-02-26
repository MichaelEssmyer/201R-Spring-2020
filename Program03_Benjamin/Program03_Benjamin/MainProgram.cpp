/*Name: Benjamin Nguyen
Student ID: 16295123
Program 03
Computer Science 201R*/



#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


using namespace std;

/*function to print raw information*/
void display_Info(int ID[], string first[], string last[], string city[], string state[], double GPA[], int size)
{
	cout << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << left << setw(5) << ID[i] << left << setw(12) << first[i] << left << setw(15) << last[i];
		cout << right << setw(15) << city[i] << right << setw(12) << state[i] << right << setw(16) << GPA[i] << endl;
	}
}

/*function to sort information due to city*/
void display(int ID[], string first[], string last[], string city[], string state[], double GPA[], int size)
{
	/*Use selection sort to sort the information ordered by cities (based on the alphabet)*/
	for (int i = 0; i < size - 1; ++i)
	{
		int smallest = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (city[j] < city[smallest])
			{
				smallest = j;
			}
		}
		/*swap*/
		int temp1 = ID[i];
		ID[i] = ID[smallest];
		ID[smallest] = temp1;

		string temp2 = first[i];
		first[i] = first[smallest];
		first[smallest] = temp2;

		string temp3 = last[i];
		last[i] = last[smallest];
		last[smallest] = temp3;

		string temp4 = city[i];
		city[i] = city[smallest];
		city[smallest] = temp4;

		string temp5 = state[i];
		state[i] = state[smallest];
		state[smallest] = temp5;

		double temp6 = GPA[i];
		GPA[i] = GPA[smallest];
		GPA[smallest] = temp6;
	}
	/*output the result*/
	for (int i = 0; i < size; ++i)
	{
		cout << left << setw(5) << ID[i] << left << setw(12) << first[i] << left << setw(15) << last[i];
		cout << right << setw(15) << city[i] << right << setw(12) << state[i] << right << setw(16) << GPA[i] << endl;
	}
}

/*function to count students from each city*/
void final_output(int ID[], string first[], string last[], string city[], string state[], double GPA[], int size)
{
	display(ID, first, last, city, state, GPA, size); /*recall function display*/
	int count1=0, count2 = 0, count3 = 0, count4 = 0, num_students[4];
	for (int i = 0; i < size; ++i)
	{
		if (city[i] == "Kansas")
		{
			count1++;
		}
		else if (city[i] == "Independence")
		{
			count2++;
		}
		else if (city[i] == "LeesSummit")
		{
			count3++;
		}
		else if (city[i] == "Liberty")
		{
			count4++;
		}
	}
	/*output the result*/
	cout << endl << endl;
	cout << "*****We have " << count1 << " students from Kansas this year*****" << endl;
	cout << "*****We have " << count3 << " students from Lees Submmit this year*****" << endl;
	cout << "*****We have " << count4 << " students from Liberty this year*****" << endl;
	cout << "*****We have " << count2 << " students from Independence this year*****" << endl;
}
/*MMMMMMMMMMMMMAAAAAAAAAAIIIIIIIINNNNNNNNNNNNNNN */
int main()
{
	/*initialize and declare variables*/
	const int Size = 10;
	int id[Size], user_choice;
	double gra[Size];
	string f[Size], l[Size], ci[Size], sta[Size], line, ARRAY[Size];
	ifstream filein;

	/*open the file "Student_Info.txt"  */
	filein.open("Student_Info.txt");

	/*check if the file is opening*/
	if (!filein.is_open())
	{
		cout << "Could not open the file, please check if the file is in right place.";
		return 1;
	}
	/* print the menu*/
	cout << "Welcome to Student Center" << endl;
	cout << "1 - Display student Info" << endl;
	cout << "2 - Display student Info sorted by City" << endl;
	cout << "3 - Display Student Info sorted by City and Total number of each student in each City" << endl;
	cout << "4 - Exit" << endl;
	
	/*read and store the data of the file in a big array*/
	while (!filein.eof())
	{

		for (int i = 0; i < Size; ++i)
		{
			getline(filein, line);
			ARRAY[i] = line;
			/*use stream string to push data to each specific array*/
			istringstream inSS(ARRAY[i]);
			inSS >> id[i];
			inSS >> f[i];
			inSS >> l[i];
			inSS >> ci[i];
			inSS >> sta[i];
			inSS >> gra[i];
		}
		filein.close();
	}
	/*ask user to choose an option*/
	while (true) /*while loop*/
	{
		cout << endl;
		cout << "Please choose an option >>> ";
		cin >> user_choice;
		if (user_choice == 1) /* raw information of student*/
		{
			display_Info(id, f, l, ci, sta, gra, Size);	
		}
		else if (user_choice == 2) /*information sorted following cities*/
		{
			display(id, f, l, ci, sta, gra, Size);
		}
		else if (user_choice == 3) /*calculate students in each city*/
		{
			final_output(id, f, l, ci, sta, gra, Size);
		}
		else if (user_choice == 4) /*if user choose 4, the program will stop */
		{
			cout << endl;
			cout << "HAVE A GREAT DAY!";
			break; /*get out of the while loop*/
		}
		else /*if user choose an invalid choice, the program will ask the user to choose a valid one again*/
		{
			cout << "Please choose a valid input" << endl;
			cout << endl;
			cout << "Please choose an option >>> ";
			cin >> user_choice;
		}
	}





	system("pause"); /*the balck board will not disappear when the program stop running*/
	return 0; /* return value for int main*/

}