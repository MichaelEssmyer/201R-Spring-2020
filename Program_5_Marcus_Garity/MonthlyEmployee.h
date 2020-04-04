#pragma once
#include "Employee.h"
class MonthlyEmployee : public Employee {
private:
	int rank;
	static int amountofMonthly;
public:
	MonthlyEmployee() : Employee(), rank(10) { amountofMonthly++; }
	MonthlyEmployee(std::string, std::string, int);
	~MonthlyEmployee() { amountofMonthly--; }

	//sets rank
	bool SetRank(int);

	//returns rank
	int GetRank() const;

	//returns type of Employee
	std::string GetType()const override;


	// same description as Employee just tailored for Monthly Employee. So writes Name, ID, Rank from input stream.
	bool virtual ReadData(std::istream&) override;

	// same desciption as Employee just tailored for Monthly Employee. So writes Type, Name,Id, and Rank to output stream.
	bool virtual WriteData(std::ostream&)const override;

	//output static class member for total amount of Monthly Employees
	static int readAmount();
};