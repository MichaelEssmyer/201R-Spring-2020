#pragma once
#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Employee
{
public:
	string Getname();
	string GetId() const;
	void SetName(const string& NewName);
	void SetId(const string& NewId);
	virtual string GetType() { return "Employee"; };
	virtual bool ReadData(istream& inSS) = 0;
	virtual bool WriteData(ostream& outSS) = 0;
protected:
	string name = "";
	string id = "";
};

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee();
	char GetExpertEmployee() const;
	double GetSalary();
	virtual string GetType() override;
	bool SetExpertEmployee(char NewExpert);
	bool SetSalary(double NewSalary);
	virtual bool ReadData(istream& inSS)  override;
	virtual bool WriteData(ostream& outSS)  override;
private:
	double Salary;
	char exp;
};
class MonthlyEmployee : public Employee
{
public:
	MonthlyEmployee();
	virtual string GetType() override;
	bool ReadData(istream& inSS)  override;
	bool WriteData(ostream& outSS)  override;
	bool SetRank(int value);
	int GetRank();

private:
	int ranking;
};



#endif
