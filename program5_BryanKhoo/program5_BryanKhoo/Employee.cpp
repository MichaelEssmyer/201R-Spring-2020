#include "Employee.h"
//Employee constructor that initializes its private members, the default value for name is empty string and ID is 0
Employee::Employee(std::string givenName, std::string givenID) {
	this->name = givenName;
	this->ID = givenID;
}
//method that sets the name of the employee
void Employee::SetName(const std::string& NewName) {
	name = NewName;
}
//method that sets the ID of the employee 
void Employee::SetID(const std::string& NewId) {
	ID = NewId;
}

