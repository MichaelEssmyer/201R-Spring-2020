#include "HourlyEmployee.h"
#include <stdexcept>
#include <cctype>




HourlyEmployee::HourlyEmployee(const string& name,const string& ID, char rating, double salary) : Employee(name, ID){
	this->rating = rating;
	this->salary = salary;
	this->name = name;
	this->ID = ID;

}

char HourlyEmployee::GetExpertEmployee() const {
	return rating;

}
double HourlyEmployee::GetSalary() const {//Returns salary of Employee
	return salary;
}
string HourlyEmployee::GetType() const {//Returns type of Employee
	return "Hourly Employee";
}


bool HourlyEmployee::SetSalary(double NewSalary) {//Check to see if salary is in a certain range 
	if (NewSalary >= 1000 && NewSalary <= 10000) {
		salary = NewSalary;
		return true;

	}
	else {
		return false;
	}
}
bool HourlyEmployee::SetExpertEmployee(char NewExpert) {//Check to see if Hourly Employee is correct if not returns false
	if (NewExpert == 'T' || NewExpert == 't') {
		rating = 'T';
		return true;
	}
	if (NewExpert == 'F' || NewExpert == 'f') {
		rating = 'F';
		return true;
	}
	else {

		return  false;
	}
}
bool HourlyEmployee::ReadData(istream& in) {
	Employee::ReadData(in);
	string temp;//Temp varaible for reading in
	string check;//Check
	char NewExpert;//Temp expert
	double EmployeeSalary;//temp salary
	in >> NewExpert;
	getline(in, temp);
	in >> EmployeeSalary;
	getline(in, check);
	if (!SetSalary(EmployeeSalary)) {
		cout << name << " has an invalid salary. For now their salary been set to N/A." << endl;
		cout << endl;
		
	}
	if (!SetSalary(EmployeeSalary)) {
		
		//Setthe salary
	}
	if (!SetExpertEmployee(NewExpert)) {
		cout << name << " has an invalid Expert Ranking. For now their ranking has been reset to F" << endl;

	}
	SetExpertEmployee (NewExpert);//Set the expert Employee
	
	return in.good(); //Check to see if everything is good

	



}
bool HourlyEmployee::WriteData(ostream& out) const {
	out << GetType() << endl;
	Employee::WriteData(out);
	out << rating<< endl;
	if (salary == 0) {//If its zero just output N/a
		out << "N/A" << endl;
	}
	else {
		out << salary << endl;

	}
	
	return out.good();


}

	

