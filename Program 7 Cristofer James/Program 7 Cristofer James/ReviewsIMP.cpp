//Cristofer James
//CS201R Spring 2020
//Program 7
#include "Reviews.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <iterator>
using namespace std;

Reviews::Reviews(){}

void Reviews::updateMap(string name, int rating)
{//Updates the Map elements using input from a file
	if (Map.find(name) != Map.end())
	{//If the key exists, update the number of ratings and rating sum integers
		Map[name].first++;
		Map[name].second += rating;
	}
	else
	{//If the key doesn't exist, create an entry for it
		Map.emplace(name, pair<int, int>());
		Map[name].first = 1;
		Map[name].second = rating;
	}
}

int Reviews::getNumReviews(string name)
{//Returns the number of reviews which is the first pair element in the map
	int numReviews = Map[name].first;
	return numReviews;
}

double Reviews::getAverageRating(string name)
{//Returns the average rating for the map key using the pair containing the number of ratings and sum of ratings for that key
	double avgRating;
	double numReviews = Map[name].second;

	avgRating = static_cast<double>(Map[name].second) / static_cast<double>(Map[name].first);
	return avgRating;
}

void Reviews::print()
{//Prints the map information in a structured format
	for (itr = Map.begin(); itr != Map.end(); itr++)
	{//Outputs the info for each map key to the screen
		cout << itr->first << ":";
		cout << setw(10) << "\t" << getNumReviews(itr->first) << " reviewers.";
		cout << setw(10) << "\tAverage of " << getAverageRating(itr->first) << "/5" << endl;
	}
}