#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ios>

using namespace std;
//declare all functions 
void Menu();
void display_Info(int iD[], string firstName[], string lastName[], string city[], string state[], double gpa[], int size);
void display(int iD[], string firstName[], string lastName[], string city[], string state[], double gpa[], int size);
vector<vector <int>> OrderOfCity(string city[], int size);
vector <string> NameOfCity(string city[], int size);
void count_city(string city[], string state[], int size);


int main() {
	//declare all variables and arrays needed
	fstream fin; 
	const int SIZE = 10;
	int iD[SIZE];
	string first[SIZE];
	string last[SIZE];
	string city[SIZE];
	string state[SIZE];
	double gpa[SIZE];
	int index;
	int userInput;
	
	fin.open("input.txt");

	//loop to keep extracting data until index reaches 10
	for (index = 0; index < SIZE; index++) {
		fin >> iD[index] >> first[index] >> last[index] >> city[index] >> state[index] >> gpa[index];
	}

	do {
		Menu();
		cout << "Please choose an option" << endl;
		cin >> userInput;
		cout << endl;
		//switch case to give response to user depending on the input
		switch (userInput) {
		case 1: display_Info(iD, first, last, city, state, gpa, SIZE); break;
		case 2: display(iD, first, last, city, state, gpa, SIZE); break;
		case 3: display(iD, first, last, city, state, gpa, SIZE); count_city(city, state, SIZE); break;
		case 4: break;
		default: cout << "Please input valid choice" << endl;
		}
	} while (userInput != 4);

	return 0;
}
//function for the menu which displays all the options for the user
void Menu() {
	cout << "Welcome to Student Center" << endl;
	cout << "1 - Display Student Info" << endl;
	cout << "2 - Display Student Info sorted by City" << endl;
	cout << "3 - Display Student Info and Total number of student in each City" << endl;
	cout << "4 - Exit" << endl;
	cout << endl;
}
//function for displaying all the student info without arranging anything
void display_Info(int iD[], string firstName[], string lastName[], string city[], string state[], double gpa[], int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(10) << right << iD[i];
		cout << setw(15) << right << firstName[i];
		cout << setw(15) << right << lastName[i];
		cout << setw(15) << right << city[i];
		cout << setw(10) << right << state[i];
		cout << setw(10) << right << gpa[i] << endl;
	}
	cout << endl;
	
}
//function to display all the student info with their cities in order
void display (int iD[], string firstName[], string lastName[], string city[], string state[], double gpa[], int size) {
	bool exist = false;
	string temp;
	vector <vector<int>> order;
	//use order to call OrderOfCity to get the actual index of the ordered list 
	order = OrderOfCity(city, size);
	//since order is a double vector, the size of each individual vector is different, so have inner loop to accomadate the size with their respective sizes
	//and the outer loop's is the actual outer vector size 
	for (int i = 0; i < order.size(); i++) {
		for (int j = 0; j < order.at(i).size(); j++) {
			cout << setw(10) << right << iD[order.at(i).at(j)];
			cout << setw(15) << right << firstName[order.at(i).at(j)];
			cout << setw(15) << right << lastName[order.at(i).at(j)];
			cout << setw(15) << right << city[order.at(i).at(j)];
			cout << setw(10) << right << state[order.at(i).at(j)];
			cout << setw(10) << right << gpa[order.at(i).at(j)] << endl;
		}
	}
	cout << endl;
}
//function that outputs the number of students in each city
void count_city(string city[], string state[], int size) {
	vector <string> cityNames;
	vector <vector<int>> numberOfCity;
	//have city name call nameOfCity to have the list of cities in the array city
	cityNames = NameOfCity(city, size);
	//have numberOfCity call OrderOfCity to have a ordered vector of city 
	numberOfCity = OrderOfCity(city, size);
	cout << endl;
	for (int i = 0; i < numberOfCity.size(); i++) {
		cout << setw(5) << right << "";
		//since the vector is based on an ordered list of cities and the cityNames has the same order of cities, they can use the same index
		cout << setfill('*') << setw(5) << "" << setfill(' ') << " We have " << numberOfCity.at(i).size() << " students from " << cityNames.at(i) << " this year ";
		cout << setfill('*') << setw(5) << "" << setfill(' ') << endl;
	}
	cout << endl;
}
//function that returns a vector which stores the cities that are present in the city array, in order
vector <string> NameOfCity(string city[], int size) {
	string temp;
	bool exist = false;
	//create a vector to store all the names of the city in the file 
	vector <string> nameOfCity;
	//put the first city into the vector
	nameOfCity.push_back(city[0]);
	//loop to see if the city in the list is the the vector
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			//if the city is already found in the vector, exist will be true and break out of the inner loop
			if (city[i] == nameOfCity.at(j)) {
				exist = true;
				break;
			}
		}
		//if city is not found in the vector, add the city into the vector
		if (exist == false) {
			nameOfCity.push_back(city[i]);
		}

	}
	//loop to arrange the cities in order
	for (int i = 0; i < nameOfCity.size() - 1; i++) {
		//if the next coming city is lesser than the current city, swap them
		if (nameOfCity.at(i) > nameOfCity.at(i + 1)) {
			temp = nameOfCity.at(i + 1);
			nameOfCity.at(i + 1) = nameOfCity.at(i);
			nameOfCity.at(i) = temp;
		}
	}

	return nameOfCity;
}
//function that returns a double vector with an index which is in order by cities
vector<vector <int>> OrderOfCity(string city[], int size) {
	//declare a vector and a double vector
	vector <vector<int>> order;
	vector <string> nameOfCity;
	//use NameOfCity to call NameOfCity and store the lists of city mentioned in the city array
	nameOfCity = NameOfCity(city, size);
	//have the outer vector have the same size as the nameOfCity vector
	order.resize(nameOfCity.size());
	//a loop to store each city's index into seperate vectors within a vector 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < nameOfCity.size(); j++) {
			//if the city is the same as the city in the vector, use the index of the city in the vector to store the city in the double vector
			//this ensures that the the student's order will not be mixed up, so according to each city, the students are in order as well 
			if (city[i] == nameOfCity.at(j)) {
				order.at(j).push_back(i);
			}
		}
	}

	return order;
}