#pragma once
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class Employee {
	public:
		Employee(const string& name = "0" , const string& ID ="0");
		void SetName(const string& name);//Set name of Employee
		void SetID(const string& ID);//Set ID of Employee
		string GetName() const;//Return ID
		string GetID() const;//Return ID of Employee
		virtual string GetType() const;//Get the employee type
		virtual bool ReadData(istream& userFile) = 0;//Read ID and Name of Employee
		virtual bool WriteData(ostream& userFile)const = 0; //Write ID and Name to file.



	protected:
		string name = "0";
		string ID = "0";

};