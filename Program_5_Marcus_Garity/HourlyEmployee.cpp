#include "HourlyEmployee.h"


#include <iostream>
#include <string>
#include <fstream>

// default contructor,  not going to care to much about this since I have private data members. >.>;
HourlyEmployee::HourlyEmployee() : Employee(), expert('N'),salary(-1)  {
	amountofHourly++;
}


// contructer with paramater in intializing list.
HourlyEmployee::HourlyEmployee(std::string name, std::string ID, char expert, double salary=-1): Employee(name,ID), expert(expert), salary(salary) {
	amountofHourly++;
}


// Default Deconstructer. No pointers so Nothing to worry about.
HourlyEmployee::~HourlyEmployee() { 
	
	amountofHourly--; 

}


//shallow copy
HourlyEmployee& HourlyEmployee::operator=(const HourlyEmployee& objToCopy) {

	if (this != &objToCopy) {
	
		*(this) = objToCopy;
	
	}
	return *this;
}


char HourlyEmployee::GetExpertEmployee() const {
	return expert;
}

double HourlyEmployee::GetSalary() const {
	return salary;
}



std::string HourlyEmployee::GetType() const{
	return "Hourly Employee";
}

bool HourlyEmployee::SetExpertEmployee(char NewExpert) {
	
	if (NewExpert == 'T' || NewExpert == 'F') {

		this->expert = NewExpert;
		return true;
	}
	else
		return false;
}

bool HourlyEmployee::SetSalary(double NewSalary) {

	if (NewSalary >= 1000 && NewSalary <=10000) {
		this->salary = NewSalary;
		return true;
	}
	else
		return false;
}

bool HourlyEmployee::ReadData(std::istream& in)  {
	std::string newName;
	std::string newID;
	char newExpert;
	double newSalary;
	bool valid1 = true;
	bool valid2 = true;
	std::getline(in, newName);
	
	std::getline(in, newID);

	in >> newExpert;
	in.ignore();
	in >> newSalary;
	in.ignore();

	
	this->SetId(newID);
	this->SetName(newName);
		
	valid1 = (this->SetSalary(newSalary));
	
	valid2 = (this->SetExpertEmployee(newExpert));
		


	
	if (valid1 == true && valid2 == true && in.good())
		return true;
	else
		return false;


}

bool HourlyEmployee::WriteData(std::ostream& out) const {

	out << this->GetType() << std::endl;
	out << this->GetName() << std::endl;
	out << this->GetId() << std::endl;
	out << this->GetExpertEmployee() << std::endl;
	out << this->GetSalary()<< std::endl;
	if (out.good())
		return true;
	else
		return false;

}

int HourlyEmployee::amountofHourly;



int HourlyEmployee::readAmount() {
	return amountofHourly;
}