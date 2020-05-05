#include "MonthlyEmployee.h"

MonthlyEmployee::MonthlyEmployee(const string& name , const string& ID, int rank) : Employee(name, ID) { //Default constructor

	this->rank = rank;

}
bool MonthlyEmployee::SetRank(int ranking) {//Set the rank of an employee
	if (ranking >= 1 && ranking <= 10) {
		rank = ranking;
		return true;
	}
	else {
		return false;
	}
}

bool MonthlyEmployee::ReadData(istream& in) {//Read Employees data from file
	Employee::ReadData(in);
	int rating;
	string temp;
	in >> rating;
	getline(in, temp);

	if (in.good()) {
		if (SetRank(rating)) {
			return true;
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
	

	
}

bool MonthlyEmployee::WriteData(ostream& out)const {//Write data to file
	out << GetType() << endl;
	Employee::WriteData(out);
	out << rank << endl;
	return out.good();

}

string MonthlyEmployee::GetType()const {
	return "Monthly Employee";
}