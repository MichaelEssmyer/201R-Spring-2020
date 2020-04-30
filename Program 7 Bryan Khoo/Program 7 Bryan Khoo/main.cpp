#include <iostream>
#include <map>
#include <fstream>
#include <string>

//function declaration 
void readData(std::istream& fin, std::map<std::string, double>& restaurant, std::map<std::string, int>& count);

int main() {
	std::ifstream fin;
	//open file called ratings 
	fin.open("ratings.txt");
	//if file can't be opened, output error message 
	if (!fin.is_open()) {
		std::cout << "Open file failed" << std::endl;
	}
	//create 2 maps, both has the restaurant names but one holds the average ratings and the other holds the total number of ratings for that restaurant
	std::map<std::string, double> restaurantDetails;
	std::map<std::string, int> reviewCount;
	//call read data and pass the 2 maps by reference 
	readData(fin, restaurantDetails, reviewCount);
	//close file
	fin.close();
	//have a range based loop to loop through the map and since the restaurant names are the keys for the maps, we can use the key for first map on the second map 
	for (auto const& x : restaurantDetails) {
		std::cout << x.first << ":\t" << reviewCount.at(x.first) << " reviewers.\tAverage of " << x.second << "/5" << std::endl;
	}
	return 0;
}

//function definition for reading data
void readData(std::istream& fin, std::map<std::string, double>& restaurant, std::map<std::string, int>& count) {
	double rating, average;
	int numOfInput;
	int numOfRatings;
	std::string name;
	fin >> numOfInput;
	fin.ignore();
	//read the file n number of times, n is the first input in the first which indicates the number of inputs will be coming after it
	for (int i = 0; i < numOfInput; ++i) {
		getline(fin, name);
		fin >> rating;
		fin.ignore();
		if (fin.fail()) {
			break;
		}
		//if the name of the restaurant does not exist, add the name and rating into the map 
		//add the name and count 1 into another map 
		if (restaurant.count(name) == 0) {
			restaurant.emplace(name, rating);
			count.emplace(name, 1);
		}
		//if the name of the restaurant already exists in the map, add the rating together with the rating held in the map
		//add 1 to the count of the restaurant in the other map
		else {
			numOfRatings = count.at(name) + 1;
			rating = restaurant.at(name) + rating;
			restaurant.at(name) = rating;
			count.at(name) = numOfRatings;
		}
	}
	//loop to calculate the average rating for each restaurant using the count number in one map and the total ratings in another map 
	for (auto& x : restaurant) {
		average = x.second / count.at(x.first);
		x.second = average;
	}
}