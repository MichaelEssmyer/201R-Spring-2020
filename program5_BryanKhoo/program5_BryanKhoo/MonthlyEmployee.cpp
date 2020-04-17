#include "MonthlyEmployee.h"
//MonthlyEmployee constructor that initializes rank value and its default value is 10
MonthlyEmployee::MonthlyEmployee(int rank) {
	this->rank = rank;
}

//method that sets the rank of MonthlyEmployee, if rank is not between 1 to 10, return false and use default value
bool MonthlyEmployee::SetRank(int givenRank) {
	if (givenRank >= 1 && givenRank <= 10) {
		rank = givenRank;
		return true;
	}
	return false;
}
//method that reads in data, it is almost identical with HourlyEmployee's ReadData except this method doesn't
//read experience or salary, but reads rank instead
bool MonthlyEmployee::ReadData(std::istream& fin) {
	std::string name, ID;
	int givenRank;

	fin >> name >> ID >> givenRank;
	//if reading file fails, return false
	if (fin.fail()) {
		return false;
	}
	//copy the data that was read in to the variables in HourlyEmployee
	Employee::SetName(name);
	Employee::SetID(ID);
	SetRank(givenRank);

	return true;
}
//method that writes data back into a file, very identical to HourlyEmployee's WriteData except it writes rank instead of 
//experience and salary
bool MonthlyEmployee::WriteData(std::ostream& fout) const {
	fout << GetType() << std::endl;
	fout << Employee::GetName() << std::endl;
	fout << Employee::GetID() << std::endl;
	fout << GetRank() << std::endl;

	return true;
}