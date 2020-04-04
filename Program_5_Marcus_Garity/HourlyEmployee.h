#pragma once

#include "Employee.h"
#include <iostream>

class HourlyEmployee : public Employee {
private:
	char expert;
	double salary;
	static int amountofHourly;
public:

	HourlyEmployee();
	HourlyEmployee(std::string name, std::string ID, char expert, double salary);
	~HourlyEmployee();
	HourlyEmployee& operator=(const HourlyEmployee& objToCopy);

	// ExpertEmployee value must be either 'F' (for no experience) or 'T' for expert. 
	char GetExpertEmployee() const;


	// Gets salary and returns it.
	double GetSalary() const;


	//gets type and returns it as a string "Hourly Employee."
	std::string GetType() const override;
	
	//changes expert member1
	bool SetExpertEmployee(char NewExpert);

	// sets new salary for salary member
	bool SetSalary(double NewSalary);

	// same discription as Employee.h tailored specifically for Hourly Employee. So writes Name,ID,Expert,and Salary from Input stream
	bool virtual ReadData(std::istream& in) override;

	// same description as Employee.h tailored specifically for Hourly Employee. So writes Type,Name,ID,Expert, and Salary to Ouput stream
	bool virtual WriteData(std::ostream& out) const override;

	// reads out static member for total amount of hourly employees
	static int readAmount();
};
