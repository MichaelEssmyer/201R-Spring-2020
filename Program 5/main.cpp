#include "Employee.h"
#include"HourlyEmployee.h"
#include "MonthlyEmployee.h"
#include  <cctype>

//TerrAnnie Scott
//April 2 2020
//Program 5


int main() {
	
	Employee* employees[100];
	ifstream fin;
	string fileName;//Files name will be entered in by user
	bool check = true;//keep the loop going
	string flag;//Will be H or M
	int index = 0;//The index of the array
	HourlyEmployee* hourlyPtr;//Hourly and monthly ptr
	MonthlyEmployee* monthlyPtr;
	ofstream fout;
	fout.open("output.txt");
	int cnt = 0;//cnt the amount of people in the array
	int HourlyEmploy = 0;//Count the number of Hourly Employees
	int MonthyEmploy = 0;//Number of Monthly employees
	bool error = false;//If an error was given turn to true so we wont print out if theres an error
	

	for (int i = 0; i < 100; i++) {//Set each element in the array as a null ptr
		employees[i] = nullptr;

	}
	while (check) {
		cout << "Enter the name of the file:  ";
		cin >> fileName;
		fin.open(fileName);
		if (!fin.is_open()) {//Check to see if the file is open// keep asking until the give something correct
			cout << "Could not open file. try again " << endl;
			continue;
		}
		else {
			check = false;
			continue;

		}

	}
	cin.ignore();
	
	while (fin.good ()) {
		string temp;//Read in the file
		getline(fin, temp);
		flag = temp[0];
		
		

		
	
		if (flag == "H" || flag == "h") {//if H or h then we read data into new HourlyEmployee
			employees[index] = new HourlyEmployee;
		
			employees[index]->ReadData(fin);
			index += 1;//Add to the index
			HourlyEmploy += 1;//Add to the counter

			
			
			
			
				

			

					


		}
		
		else if (flag == "M" || flag == "m") {//IF M or M we read data into hourly employee
			employees[index]= new MonthlyEmployee();
			employees[index]->ReadData(fin);
			index += 1;
			MonthyEmploy += 1;

			
			


		}

		else {
			
	
			if (flag != "H" || flag != "M" || flag!="h"||flag!="m") {
				cout << "Inapproaiate Output please ask Employees to update, Then try again" << endl;
	
				error = true;

				break;

			}
			
			
			
		}
		
	
		

			
			


	}
	if (error == false) {
		cout << "Amount of Hourly Employees: " << HourlyEmploy << endl;
		cout << "Amount of Monthly Employees: " << MonthyEmploy << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < index; j++) {
				if (i == 0) {
					if (employees[j]->GetType() == "Monthly Employee") {
						employees[j]->WriteData(fout);
					}
				}
				if (i == 1) {
					if (employees[j]->GetType() == "Hourly Employee") {
						employees[j]->WriteData(fout);
					}

				}

			}
		}

	}

	


	
	




	fin.close();
	fout.close();
	







	return 0;
}