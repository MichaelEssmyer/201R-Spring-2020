// name: Marcus Garity
// email: mkgdg4@mail.umkc.edu
// class: CS201
// Program: Program 5
// creation date: 3/29/2020
// due date: 4/02/2020










#include "Employee.h"
#include "HourlyEmployee.h"
#include "MonthlyEmployee.h"


#include <fstream>
#include <stdexcept>

// nullptr's the entire array
void SetNull(Employee* ArrayPtr[], int size);

// reads file
void readfile(Employee* ArrayPtr[], int size, std::ifstream& in);

//reports number of Hourly and Monthly Employees using static member functions
void report();

// writes to output file
void writefile(Employee* ArrayPtr[], int size, std::ofstream& out);

// releases memomory and nullptr's array.
void clearMem(Employee* ArrayPtr[], int size);

int main()

{
	int const size = 100;
	Employee* ArrayPtr[size];
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	
	
	try 
	{
		SetNull(ArrayPtr, size);
		readfile(ArrayPtr, size, in);
		report();
		writefile(ArrayPtr, size, out);
		clearMem(ArrayPtr, size);
	}

	catch (std::runtime_error & excpt) 
	{
	
		std::cout << excpt.what() << std::endl;
		std::cout << "Program Ending" << std::endl;
	
	}

	

	in.close();
	out.close();

	std::cout << "Press Enter to Exit..." << std::endl;
	std::cin.get();
	
	return 0;

}
void SetNull(Employee* ArrayPtr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		ArrayPtr[i] = nullptr;

	}


}
void readfile(Employee* ArrayPtr[], int size, std::ifstream& in) {
	std::string readline;
	int count = 0;
	while (in.good())
	{

		std::getline(in, readline);
		if (readline == "\n" || readline == "") // Allows extra new lines in the code and between entries. Kept getting Invalid Employee flag because I had an extra newline. Thought I'd make that issue dissapear.
			continue;
		if (readline == "m" || readline == "M" || readline == "h" || readline == "H")
		{
				if (readline == "m" || readline == "M")
				{
					ArrayPtr[count] = new MonthlyEmployee();
					ArrayPtr[count]->ReadData(in);

				}

				if (readline == "h" || readline == "H")
				{
					ArrayPtr[count] = new HourlyEmployee();

					ArrayPtr[count]->ReadData(in);

					//  if (!(ArrayPtr[count]->ReadData(in)))
					//	throw std::runtime_error("File not formated properly");

				}




		}

		else
			throw std::runtime_error("Invalid Employee flag");

		


		count++;
	}



}
void writefile(Employee* ArrayPtr[], int size, std::ofstream& out) {
	int count = 0;
	while (ArrayPtr[count] != nullptr && count < size) {

		if (ArrayPtr[count]->GetType() == "Monthly Employee") 
		{
			ArrayPtr[count]->WriteData(out);
		}
		count++;
	}
	count = 0;
	while (ArrayPtr[count] != nullptr && count < size) {

		if (ArrayPtr[count]->GetType() == "Hourly Employee")
		{
			ArrayPtr[count]->WriteData(out);
		}
		count++;
	}

}
void clearMem(Employee* ArrayPtr[], int size) {
	int count = 0;
	while (ArrayPtr[count] != nullptr && count < size) {

		delete ArrayPtr[count];
		ArrayPtr[count] = nullptr;
		count++;
	}
}
void report() {

	std::cout << "Hourly Employee Count: " << HourlyEmployee::readAmount()<< std::endl;
	std::cout << "Monthly Employee Count: " <<MonthlyEmployee::readAmount() << std::endl;
	std::cout << "For a Total Employee Count: " << Employee::readAmount() << std::endl;

}