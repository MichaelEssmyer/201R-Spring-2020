#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class Employee {
public:
	Employee(std::string givenName = "", std::string givenID = "0");
	std::string GetName() const { return name; };
	std::string GetID() const { return ID; };
	void SetName(const std::string& NewName);
	void SetID(const std::string& NewId);
	virtual std::string GetType() const { return "Employee"; };
	virtual bool ReadData(std::istream& fin) = 0;
	virtual bool WriteData(std::ostream& fout) const = 0;
protected:
	std::string name;
	std::string ID;
};