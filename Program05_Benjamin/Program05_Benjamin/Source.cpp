#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Company.h"

using namespace std;

int main()
{


	Employee* each[100];
	char flag;
	int count = 0;
	int count_h = 0;
	int count_m = 0;
	ifstream filein("input.txt");
	ofstream fileout("output.txt");

	while (!filein.eof())
	{

		filein >> flag;

		if (flag == 'H')
		{
			each[count] = new  HourlyEmployee;
			each[count]->ReadData(filein);

			count_h++;

		}
		else if (flag == 'M')
		{

			each[count] = new MonthlyEmployee;
			each[count]->ReadData(filein);

			count_m++;
		}
		else
		{
			cout << "Error Message!" << endl;
			break;

		}
		count++;





	}
	filein.close();
	for (int i = 0; i < count; ++i)
	{
		if (each[i]->GetType() == "Monthly Employee")
		{
			each[i]->WriteData(fileout);
		}
	}
	for (int i = 0; i < count; ++i)
	{
		if (each[i]->GetType() == "Hourly Employee")
		{
			each[i]->WriteData(fileout);
		}
	}

	if (filein.eof())
	{
		cout << "There are " << count_h << " hourly employees!" << endl;
		cout << "There are " << count_m << " monthly employees!" << endl;
		cout << "There are total " << count << " employees in company!" << endl;

	}





	return 0;
}
