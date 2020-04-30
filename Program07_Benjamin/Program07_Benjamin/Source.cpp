#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	map<string,pair <int, double> >Res_list;
	pair<int, double> data;

	int amount, rating, count=1;
	string Res_name, space;

	ifstream filein("ratings.txt");
	ofstream fileout("output.txt");

	if (!filein.is_open())
	{
		cout << "Could not open the file, please check if the file is in right place.";
		return 1;
	}
	filein >> amount;
	
	while (!filein.eof())
	{
		getline(filein, space);
		getline(filein, Res_name);
		filein >> rating;
		if (Res_list.find(Res_name) == Res_list.end()) {
			// not found
			data.first= count;
			data.second = rating;
			Res_list.emplace(Res_name, data);
		}
		else {
			// found
			Res_list.at(Res_name).second += rating;
			Res_list.at(Res_name).first += 1;
		}
		
	}
	map <string, pair<int, double>> ::iterator it = Res_list.begin();
	map <int, double> ::iterator itt;
	for (it = Res_list.begin(); it != Res_list.end(); it++)
	{

			if ((*it).first == "")
			{
				continue;
			}
			else
			{
				cout << setw(12) << (*it).first << ": " << right << setw(10) << (*it).second.first << " reviewers." << right << "      Average of " << (*it).second.second / (*it).second.first << "/5" << endl << endl;
				fileout << setw(12) << (*it).first <<": " << right <<setw(10) << (*it).second.first << " reviewers." << right << "      Average of " << (*it).second.second / (*it).second.first << "/5" << endl << endl;
				
			}

	}
	return 0;
}