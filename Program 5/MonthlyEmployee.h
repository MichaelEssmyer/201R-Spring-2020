#pragma once
#include "Employee.h"
#include "HourlyEmployee.h"
#include <string>
using namespace std;

class MonthlyEmployee : public Employee {
public:
	MonthlyEmployee(const string& name = "0", const string& ID = "0", int rank = 10);
	virtual bool ReadData(istream& in);
	virtual bool WriteData(ostream& out) const;
	bool SetRank(int ranking);
	virtual string GetType() const;
	

private:
	int rank = 0;
};