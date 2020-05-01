//Cristofer James
//CS201R Spring 2020
//Program 7
#pragma once
#ifndef REV_H
#define REV_H
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Reviews
{
public:
	Reviews();
	void updateMap(string name, int rating);
	int getNumReviews(string name);
	double getAverageRating(string name);
	void print();

private:
	//map<name, pair<number of reviews, rating sum>
	map<string, pair<int, int>> Map;
	map<string, pair<int, int>>::iterator itr;
};
#endif