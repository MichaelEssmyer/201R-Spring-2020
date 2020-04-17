#include "HourlyEmployee.h"
//default constructor for HourlyEmployee class to set values for experiece and salary, the default valu 
//for salary is 0 and experience is F
HourlyEmployee::HourlyEmployee(char givenExperience, double salary) {
	this->experience = givenExperience;
	this->salary = salary;
}
//method that sets an employee's experience, if it isnt F or T, return false
bool HourlyEmployee::SetExpertEmployee(char newExpert) {
	if (newExpert == 'F' || newExpert == 'T') {
		experience = newExpert;
		return true;
	}
	return false;
}
//method that sets an employee's salary, if the salary is less than 1k or more than 10k, set salary to default value
bool HourlyEmployee::SetSalary(double newSalary) {
	if (newSalary >= 1000 && newSalary <= 10000) {
		salary = newSalary;
		return true;
	}
	return false;
}
//method that reads in data from a given file and sets the data into its respective types
bool HourlyEmployee::ReadData(std::istream& fin) {
	std::string name, ID;
	char experience;
	double salary;
	fin >> name >> ID >> experience >> salary;
	//if reading fails, return false
	if (fin.fail()) {
		return false;
	}
	//copy the data that was read in to the variables in HourlyEmployee
	Employee::SetName(name);
	Employee::SetID(ID);	
	SetExpertEmployee(experience);
	SetSalary(salary);

	return true;
}
//method that writes out data of the employee into a file
bool HourlyEmployee::WriteData(std::ostream& fout) const {
	//try and catch block to see if there is any errors while writing data
	try {
		fout << GetType() << std::endl;
		fout << Employee::GetName() << std::endl;
		fout << Employee::GetID() << std::endl;
		fout << GetExpertEmployee() << std::endl;
		//if an employee's salary is less than 1k, output a value to hide true salary
		if (GetSalary() < 1000) 
			fout << "-  6.27744e+66" << std::endl;
		else
			fout << GetSalary() << std::endl;
	}
	catch (...) {
		return false;
	}
	//if output successful, return true
	return true;
}