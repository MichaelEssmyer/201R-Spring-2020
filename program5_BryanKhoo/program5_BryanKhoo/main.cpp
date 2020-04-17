#include "HourlyEmployee.h"
#include "MonthlyEmployee.h"

int main() {
	//declare a character which will be used to store type of employee
	char typeOfEmployee;
	//declare an array of Employee pointers
	Employee* employees[100];
	//open file named input
	std::ifstream fin("input.txt");
	//if file doesn't open, display error message and exit program
	if (!fin.is_open()) {
		std::cout << "FILE FAILED TO OPEN" << std::endl;
		return -1;
	}
	//a for loop to initialize pointers in employees array to point to nullptr
	for (int n = 0; n < 100; n++) {
		employees[n] = nullptr;
	}
	//a for loop to keep reading file until the end of file
	for (int i = 0; !fin.eof(); i++ ) {
		//collect the type of employee 
		fin >> typeOfEmployee;
		//based on the type of employee, create an employee pointer based on the input
		if (typeOfEmployee == 'H' || typeOfEmployee == 'h') {
			employees[i] = new HourlyEmployee;
		}
		else if (typeOfEmployee == 'M' || typeOfEmployee == 'm') {
			employees[i] = new MonthlyEmployee;
		}
		//if the type of employee isnt 'h' or 'm', output error message and exit program as it is an unknown type of employee
		else {
			std::cout << "Error, there is an unknown type of employee" << std::endl;
			fin.close();
			return -1;
		}
		//use that pointer that was created to read the rest of the data in file
		employees[i]->ReadData(fin);
	}
	//close file after reading it 
	fin.close();
	//open a new file named output to write all the employee data
	std::ofstream fout("output.txt");
	//for loop to loop through employees array to write out monthly employees first 
	for (int j = 0; j < 100; j++) {
		if (employees[j] == nullptr) {
			break;
		}
		else if (employees[j]->GetType() == "Monthly Employee") {
			employees[j]->WriteData(fout);
		}
	}
	//for loop to loop through employees array to write out hourly employees into file after writing all monthly employees
	for (int k = 0; k < 100; k++) {
		if (employees[k] == nullptr) {
			break;
		}
		else if (employees[k]->GetType() == "Hourly Employee") {
			employees[k]->WriteData(fout);
		}
	}
	//after outputing the data into a file, delete all the pointers stored in the employees array 
	for (int z = 0; z < 100; z++) {
		if (employees[z] == nullptr)
			break;
		delete employees[z];
		employees[z] = nullptr;
	}
	//close file
	fout.close();

	return 0;
}