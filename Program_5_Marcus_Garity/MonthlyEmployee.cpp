#include "MonthlyEmployee.h"


MonthlyEmployee::MonthlyEmployee(std::string name, std::string ID, int rank=10): Employee(name, ID), rank(rank) {
	amountofMonthly++;
}

std::string MonthlyEmployee::GetType() const {
	return "Monthly Employee";

}

int MonthlyEmployee::GetRank() const{
	return this->rank;
}

bool MonthlyEmployee::SetRank(int rank) {

	if (rank >= 1 && rank <= 10) {
		this->rank = rank;
		return true;
	}
	return false;
}

bool MonthlyEmployee::ReadData(std::istream& in) {

	std::string newName;
	std::string newID;
	int newRank;
	bool valid = true;

	std::getline(in, newName);

	std::getline(in, newID);

	in >> newRank;
	in.ignore();



	valid = (this->SetRank(newRank));
	this->SetName(newName);
	this->SetId(newID);

	if (valid && in.good())
		return true;
	else
		return false;


}

bool MonthlyEmployee::WriteData(std::ostream& out)const {

	out << this->GetType() << std::endl;
	out << this->GetName() << std::endl;
	out << this->GetId() << std::endl;
	out << this->GetRank()<< std::endl;

	if (out.good())
		return true;
	else
		return false;

}

int MonthlyEmployee::amountofMonthly;

int MonthlyEmployee::readAmount() {
	return amountofMonthly;
}