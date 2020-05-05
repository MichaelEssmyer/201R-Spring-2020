#include "Employee.h"




Employee :: Employee(const string& name, const string& ID) {
	this->name = name;
	this->ID = ID;
}

void Employee::SetName(const string& name) {//Sets name from the file
	this->name = name;

}
void Employee::SetID(const string& ID) {//Sets the id
	this->ID = ID;

}string Employee::GetName()const {//Gets the name from the file
	return name;

}

string Employee::GetID()const {//Gets ID 
	return ID;

}
string Employee::GetType()const {//Returns Employee type
	return "Employee";
}


bool Employee::ReadData(istream& in) {//Reads in the data
	string EmployeeName;
	string EmployeeID;
	getline(in, EmployeeName);
	if (!in.good()) {//Checks to see if everything is good;
		return false;
	}
	
	getline(in, EmployeeID);
	if (!in.good()) {
		return false;
	}
	
	
	SetID(EmployeeID);
	SetName(EmployeeName);
	
	return true;

	
	
}
bool Employee::WriteData(ostream& out) const {//Writes out the data
	out << name << endl;
	if (!out.good()) {
		return false;
	}
	out << ID << endl;
	if (!out.good()) {
		return false;
	}

	return true;
}
