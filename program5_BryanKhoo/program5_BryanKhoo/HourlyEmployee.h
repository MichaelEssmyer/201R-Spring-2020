#pragma once
#include "Employee.h"

class HourlyEmployee :public Employee {
public:
	HourlyEmployee(char givenExperience = 'F', double salary = 0);
	char GetExpertEmployee() const { return experience; };
	double GetSalary() const { return salary; };
	bool SetExpertEmployee(char newExpert);
	bool SetSalary(double newSalary);
	std::string GetType() const override { return "Hourly Employee"; }
	bool ReadData(std::istream& fin) override;
	bool WriteData(std::ostream& fout) const override;
private:
	char experience;
	double salary; 
};