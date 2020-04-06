#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Company.h"
using namespace std;
void Employee::SetName(const string& NewName)
{
	this->name = NewName;
}
void Employee::SetId(const string& NewId)
{
	this->id = NewId;
}
string Employee::Getname()
{
	return name;
}
string Employee::GetId() const
{
	return id;
}
bool Employee::ReadData(istream& inSS)
{

	string inname, inid, space;
	if (inSS.good())
	{
		getline(inSS, space);
		getline(inSS, inname);
		getline(inSS, inid);
		Employee::SetName(inname);
		Employee::SetId(inid);
		return true;
	}
	return false;
}

HourlyEmployee::HourlyEmployee()
{
	name = "";
	id = "";
	Salary = 0;
	exp = '\0';
}
bool HourlyEmployee::SetExpertEmployee(char NewExpert)
{
	this->exp = NewExpert;
	if (exp == 'T')
	{
		return true;
	}
	return false;
}
bool HourlyEmployee::SetSalary(double NewSalary)
{
	this->Salary = NewSalary;
	if (Salary >= 1000 && Salary <= 10000)
	{
		return true;
	}
	return false;
}
char HourlyEmployee::GetExpertEmployee() const
{
	return exp;
}
double HourlyEmployee::GetSalary()
{
	return Salary;
}
string HourlyEmployee::GetType()
{
	return "Hourly Employee";
}
bool HourlyEmployee::ReadData(istream& inSS)
{
	if (inSS.good())
	{
		Employee::ReadData(inSS);
		double Sal;
		char Exp;

		inSS >> Exp;
		inSS >> Sal;
		HourlyEmployee::SetSalary(Sal);
		HourlyEmployee::SetExpertEmployee(Exp);
		return true;
	}
	else
	{
		return false;
	}

}


MonthlyEmployee::MonthlyEmployee()
{
	this->name = "";
	this->id = "";
	this->ranking = 0;
}
bool MonthlyEmployee::SetRank(int value)
{
	this->ranking = value;
	if (ranking >= 1 && ranking <= 10)
	{
		return true;
	}
	return false;
}
string MonthlyEmployee::GetType()
{
	return "Monthly Employee";
}
int MonthlyEmployee::GetRank()
{
	return ranking;
}

bool MonthlyEmployee::ReadData(istream& inSS)
{
	if (inSS.good())
	{
		Employee::ReadData(inSS);
		int Ra;


		inSS >> Ra;
		MonthlyEmployee::SetRank(Ra);
		return true;
	}
	else
	{
		return false;
	}
}
bool HourlyEmployee::WriteData(ostream& outSS)
{

	if (outSS.good())
	{
		outSS << HourlyEmployee::GetType() << endl;
		outSS << name << endl;
		outSS << id << endl;
		outSS << HourlyEmployee::GetExpertEmployee() << endl;
		outSS << HourlyEmployee::GetSalary() << endl << endl;

		return true;
	}
	return false;
}
bool MonthlyEmployee::WriteData(ostream& outSS)
{

	if (outSS.good())
	{
		outSS << MonthlyEmployee::GetType() << endl;
		outSS << name << endl;
		outSS << id << endl;
		outSS << MonthlyEmployee::GetRank() << endl << endl;
		return true;
	}
	return false;
}
