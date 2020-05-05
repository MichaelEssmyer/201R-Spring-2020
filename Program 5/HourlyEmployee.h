#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
public:
	HourlyEmployee(const string& name = "0", const string& ID = "0", char rating = 'F', double salary = 0 );
	char GetExpertEmployee()const;
	double GetSalary() const;
	virtual string GetType() const override;
	bool SetExpertEmployee(char NewExpert);
	bool SetSalary(double NewSalary);
	virtual bool ReadData(istream& in);
	virtual bool WriteData(ostream& out) const;


private:
	char rating;
	double salary;

};
