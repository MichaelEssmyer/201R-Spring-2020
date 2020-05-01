//Cristofer James
//CS201R Spring 2020
//Program 7
#include "Reviews.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    Reviews Ratings;
    string currName;
    int numRatings;
    int currRating;

    fin.open("ratings.txt");
    fin >> numRatings;
    for (int a = 0; a < numRatings; a++)
    {//Iterates through the input file pulling the data and passing it to the Ratings object for handling
        fin.ignore();
        getline(fin, currName);
        fin >> currRating;
        Ratings.updateMap(currName, currRating);
    }
    fin.close();
    Ratings.print();

	return 0;
}