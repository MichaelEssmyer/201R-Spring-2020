#pragma once

#include <string>
#include<iostream>



class Employee {
private:
	std::string name;
	std::string ID;
	static int amountOfEmployee;

public:

	Employee();
	Employee(std::string, std::string);
	~Employee();
	Employee& operator= (const Employee&);


	// Return Name. it's also const which means, it's not going to change name.
	std::string GetName() const; 
	//Return ID. It's also const which means, it's not going to change ID.
	std::string GetId() const;
	//Changes name
	void SetName(const std::string&);
	//changes ID
	void SetId(const std::string&);
	//return type of class "Employee" and is virtual so must be overrided in childs.
	virtual std::string GetType() const;

	/*This method attempts to read the following data from the input stream: The name, which may contain spaces but is always on a single line; then the id. 
	You will want to use getline() for this. The stream extraction (input) operator >> and getline() handle the end of line marker at the end of each line slightly differently. 
	This method is responsible for reading the appropriate data and the ending newline, so the stream is ready to read the next line. 
	This method returns true if all read operations were successful, false otherwise. (The istream.good() function will be useful.) */
	virtual bool ReadData(std::istream&) = 0;


	/*This const method writes the employee’s name and his id, each on a line by itself immediately followed by a newline.
	It also returns true if successful, false otherwise; the ostream.good() method will be useful here. */

	virtual bool WriteData(std::ostream&) const = 0;

	/*The ReadData() and WriteData() methods should be pure virtual. <-----------------------------------------------------------PURE VIRTUAL CLAUSE FOR BOTH WRITEDATA AND READDATA
	Go ahead and implement them, they'll make implementing the child classes simpler, but this is an abstract class. 
	(There are no general employees, only employees of a specific type. This class captures the data common to all company employees across all categories.) 
	The default value for the name is “0” (an empty string); the default value for the id is 0. 
	*/

	// reads out total amount of employees.
	static int readAmount();

};