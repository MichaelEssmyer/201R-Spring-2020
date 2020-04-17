#pragma once

#include "Employee.h"

class MonthlyEmployee : public Employee {
public:
	MonthlyEmployee(int rank = 10);
	std::string GetType() const override { return "Monthly Employee"; }
	bool SetRank(int givenRank);
	int GetRank() const { return rank; }
	bool ReadData(std::istream& fin) override;
	bool WriteData(std::ostream& fout) const override;
private:
	int rank;
};