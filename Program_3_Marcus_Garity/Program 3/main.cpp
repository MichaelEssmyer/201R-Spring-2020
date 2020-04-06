
//Marcus Garity
//Program 3
//Class CS201R 0004
//Creation Date 3/1/2020
//Due Date 3/5/2020






/* Note: All functions were required by assignment, so this is purely acadmeic. Otherwise, I would use structures and vectors.*/



#include <iostream>
#include <fstream>
#include <iomanip>
#include <ios>
#include <vector>

// This function will display menu to user with all options to choose from
void menu();
// This function will display all student info (ID,First,Last,City,State,GPA)
void display_info(int[], std::string[], std::string[], std::string[], std::string[],double[],int);

// This function will display all student info ordered by State, City, and Student ID
void display(int[], std::string[], std::string[], std::string[], std::string[], double[], int);


// Reads in file to arrays.
void readfile(int[], std::string[], std::string[], std::string[], std::string[], double[], int);

//This function will display the number of students applied from each City.
void count_city(std::string[], std::string[], int size);

int main() {
	
	const int size = 10;
	int ID[size];
	std::string first[size];
	std::string last[size];
	std::string city[size];
	std::string state[size];
	double GPA[size];
	char UserInput;
	
	do {

		//Read in file
		readfile(ID, first, last, city, state, GPA, size);
		//Diplay menu
		menu();
		//Ask for user Input
		std::cout << "Please choose an option:" << std::endl;
		std::cin >> UserInput;

		// This is how, I figure out how to clear standard input. 
		if (std::cin.get()!='\n') {
			
			UserInput = '5'; // Incase someone enters like 12. It doesn't set off case 1.
			while (std::cin.get() != '\n') {
				continue;
			
			}
			
		}
		std::cout << std::endl;
		// Take user input and place into switch
		switch (UserInput) {
			case '1':
				// If chosen will display file as read in.
				display_info(ID, first, last, city, state, GPA, size);
				break;
			case '2':
				// If chosen will display file ordered by state,city,and student ID.
				display(ID, first, last, city, state, GPA, size);
				break;
			case '3':
				// If chose will do case 2 as well as display city count.
				display(ID, first, last, city, state, GPA, size);
				count_city(city, state, size);
				break;
			case '4':
				// Does nothing and breaks out of switch
				break;
			default:
				// Any other input case comes here to inform user of Invalid Input
				std::cout << "Please input valid Choice" << std::endl;
				std::cout << std::endl;
				break;
			}
	// checks if UserInput is 4. If it is, it will drop out of program.
	} while (UserInput != '4');

	//Program End Sequence
	std::cout << "Have a great day!" << std::endl;
	std::cout << "Press Enter to exit program."<<std::endl;
	std::cin.get();


	return 0;
}



void count_city(std::string city[], std::string state[], int size) {
	/*takes in arrays and counts how many students are from what city, can handle cities from different states with same names.*/
	std::vector<std::string> state_vec;
	std::vector<std::string> city_vec;
	std::vector<int> city_count;
	int j;
	bool doesexist;
	for (int i = 0; i < size; i++) {
		doesexist = false;
		for (j = 0; j < size; j++) {
			if ( city_vec.size()>j && city[i] == city_vec.at(j) && state[i] == state_vec.at(j)) {
				doesexist = true;
				break;
			}
		
		}
		if (doesexist) {
			city_count.at(j) += 1;
		
		}
		else {
			state_vec.push_back(state[i]);
			city_vec.push_back(city[i]);
			city_count.push_back(1);

		}
	
	}

	for (unsigned int i = 0; i < state_vec.size(); i++) {
		std::cout << std::setw(19) << std::right << "***** We have " << city_count.at(i) << " students from "<<city_vec.at(i)<<", "<<state_vec.at(i)<<" this year *****" << std::endl;
	}


	

	std::cout << std::endl;
}
void readfile(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[], int size) {
	// Reads in file, requires file to not be accessed by another program.
	std::ifstream fin("Student_Info.txt");
	for(int i = 0; i < size; i++) {
		if(fin.good())
			fin >> ID[i] >> first[i] >> last[i] >> city[i] >> state[i] >> GPA[i];
	}

	fin.close();

}
void display(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[], int size) {
	// takes in 6 arrays, sorts them and displays them.
	int int_temp;
	std::string string_temp;
	double double_temp;


	// This sort is for states
	for (int i = 0; i < size; i++) {

		
		int smallest = i;
		for (int j = i; j < size; j++) {
		
			if (state[smallest] < state[j]) {
				smallest = j;
			
			}

		}
		
		
			int_temp = ID[i];
			ID[i] = ID[smallest];
			ID[smallest] = int_temp;

			string_temp = first[i];
			first[i] = first[smallest];
			first[smallest] = string_temp;

			string_temp = last[i];
			last[i] = last[smallest];
			last[smallest] = string_temp;

			string_temp = city[i];
			city[i] = city[smallest];
			city[smallest] = string_temp;

			string_temp = state[i];
			state[i] = state[smallest];
			state[smallest] = string_temp;

			double_temp = GPA[i];
			GPA[i] = GPA[smallest];
			GPA[smallest] = double_temp;


		
	
	}
	// This sort is for cities so long as the states are equal
	for (int i = 0; i < size; i++) {


		int smallest = i;
		for (int j = i; j < size; j++) {

			if ( city[smallest].size() > city[j].size() && state[smallest] == state[j]) {
				smallest = j;

			}

		}


		int_temp = ID[i];
		ID[i] = ID[smallest];
		ID[smallest] = int_temp;

		string_temp = first[i];
		first[i] = first[smallest];
		first[smallest] = string_temp;

		string_temp = last[i];
		last[i] = last[smallest];
		last[smallest] = string_temp;

		string_temp = city[i];
		city[i] = city[smallest];
		city[smallest] = string_temp;

		string_temp = state[i];
		state[i] = state[smallest];
		state[smallest] = string_temp;

		double_temp = GPA[i];
		GPA[i] = GPA[smallest];
		GPA[smallest] = double_temp;




	}
	// This sort is for id's so long as the cities are equal.
	for (int i = 0; i < size; i++) {


		int smallest = i;
		for (int j = i; j < size; j++) {

			if (ID[smallest]>ID[j] && city[smallest] == city[j] && state[smallest] == state[j]) {
				smallest = j;

			}

		}


		int_temp = ID[i];
		ID[i] = ID[smallest];
		ID[smallest] = int_temp;

		string_temp = first[i];
		first[i] = first[smallest];
		first[smallest] = string_temp;

		string_temp = last[i];
		last[i] = last[smallest];
		last[smallest] = string_temp;

		string_temp = city[i];
		city[i] = city[smallest];
		city[smallest] = string_temp;

		string_temp = state[i];
		state[i] = state[smallest];
		state[smallest] = string_temp;

		double_temp = GPA[i];
		GPA[i] = GPA[smallest];
		GPA[smallest] = double_temp;




	}



	//Already made, so might as well use it.
	display_info(ID, first, last, city, state, GPA, size);



}
void display_info(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[], int size) {
	//takes in arrays and displays them.
	
	for (int i = 0; i < size; i++) {
		std::cout <<
			std::setw(10) << std::right << ID[i] <<
			std::setw(13) << std::right << first[i] <<
			std::setw(13) <<std::right <<last[i]<<
			std::setw(20) << std::right << city[i] <<
			std::setw(8) << std::right << state[i] <<
			std::setw(8) << std::right << GPA[i] <<
			std::endl;
	}
	std::cout << std::endl;
}
void menu() {
	//outputs a menu
	std::cout << "Welcome to Student Center" << std::endl;
	std::cout << "1- Display Student Info"<<std::endl;
	std::cout << "2- Display Student Info sorted by City"<<std::endl;
	std::cout << "3- Display Student Info sorted by City and Total number of student in each City"<<std::endl;
	std::cout << "4- Exit"<<std::endl;
	std::cout << std::endl;
}