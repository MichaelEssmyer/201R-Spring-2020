#include "Employee.h"



Employee::Employee():name("0"),ID("0") {
	amountOfEmployee++;
};
Employee::~Employee() {
	amountOfEmployee--;
};
Employee::Employee(std::string name="0", std::string ID="0") {
	amountOfEmployee++;
	this->name = name;
	this->ID = ID;
}
Employee& Employee::operator= (const Employee& objToCopy) {

	if (this != &objToCopy) 
	{
		(*this) = objToCopy;
	}
	return *this;
}




std::string Employee::GetName() const 
{
	return name;
}
std::string Employee::GetId() const
{
	return ID;
}
//Changes name
void Employee::SetName(const std::string& NewName) {
	this->name = NewName;
}
//changes ID
void Employee::SetId(const std::string& NewId) {
	this->ID = NewId;
}

//reads out type of Employee
std::string Employee::GetType() const {
	return "Employee";
}


//Declaration of static Variables <--------------------------------------it's here.
int Employee::amountOfEmployee;

//read out total amount of Employees
int Employee::readAmount() {
	return amountOfEmployee;

}