//
//  functions.cpp
//  NewProgram3
//
//  Created by Davith Lon on 2/26/20.
//  Copyright © 2020 Davith Lon. All rights reserved.
//

#include <iomanip>
#include "city.hpp"
#include "functions.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>

void menu(void){

    std::cout << "Welcome to the Student Center" << std::endl;
    std::cout << "1- Display Student Info" << std::endl;
    std::cout << "2- Display Student Info Sorted by Cities" << std::endl;
    std::cout << "3- Display Student Info Sorted by Cities and Total # of Students in Each City" << std::endl;
    std::cout << "4- Exit" << std::endl;

}

void display(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[],int size){
    
    for (int i = 0; i < size; ++i){
        std::cout << std::setw(20) << ID[i];
        std::cout << std::setw(20) << first[i];
        std::cout << std::setw(20) << last[i];
        std::cout << std::setw(20) << city[i];
        std::cout << std::setw(20) << state[i];
        std::cout << std::setw(20) << GPA[i] << std:: endl;
    }

    std::cout << std::endl;

}

void display_Info(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[], int size){
    
    std::vector <int> mySortedIndexes;
    std::vector <class city> unsortedCities;
    
    class city city0 (city[0], 0);
    class city city1(city[1], 1);
    class city city2(city[2], 2);
    class city city3(city[3], 3);
    class city city4(city[4], 4);
    class city city5(city[5], 5);
    class city city6(city[6], 6);
    class city city7(city[7], 7);
    class city city8(city[8], 8);
    class city city9(city[9], 9);
    
    unsortedCities = {city0, city1, city2, city3, city4, city5, city6, city7, city8, city9};
    
    mySortedIndexes = createVectorOfSortedCityIndices(unsortedCities);
    
    for (int i = 0; i < size; ++i){
        int j = mySortedIndexes.at(i);
        std::cout << std::setw(20) << ID[j];
        std::cout << std::setw(20) << first[j];
        std::cout << std::setw(20) << last[j];
        std::cout << std::setw(20) << city[j];
        std::cout << std::setw(20) << state[j];
        std::cout << std::setw(20) << GPA[j] << std:: endl;
    }
    
    std::cout << std::endl;

}

void count_city(std::string city[], std::string state[],int size){
    
    std::vector <int> mySortedIndexes;
    std::vector <class city> unsortedCities;
    
    class city city0 (city[0], 0);
    class city city1(city[1], 1);
    class city city2(city[2], 2);
    class city city3(city[3], 3);
    class city city4(city[4], 4);
    class city city5(city[5], 5);
    class city city6(city[6], 6);
    class city city7(city[7], 7);
    class city city8(city[8], 8);
    class city city9(city[9], 9);
    
    unsortedCities = {city0, city1, city2, city3, city4, city5, city6, city7, city8, city9};
    
    mySortedIndexes = createVectorOfSortedCityIndices(unsortedCities);
    
    int count;
    
    for(int i = 0; i < (size); i+= count){
        count = 1;
        for(int j = i; j < (size); ++j){
            if(j+1 == 10){
                std::cout << "***** We Have " << count << " students from " << city[mySortedIndexes.at(j)] << " this year ******" << std::endl << std::endl;
                break;
            }
            if(city[mySortedIndexes.at(j)] == city[mySortedIndexes.at(j + 1)]){
                ++count;
            }
            else {
                std::cout << "***** We Have " << count << " students from " << city[mySortedIndexes.at(j)] << " this year ******" << std::endl;
                break;
            }
        }
    }
}

std::vector<int> createVectorOfSortedCityIndices(std::vector<city> thisVector){
    
    std::vector <int> sortedIndexs;
    int key;
    
    for(int i = 0; i < thisVector.size() - 1; ++i){
        key = i;
        for(int j = i + 1; j < thisVector.size(); ++j ){
            if(thisVector.at(j).cityName < thisVector.at(key).cityName){
                key = j;
            }
        }
        
        city temp("",0);
    
        temp = thisVector.at(key);
        thisVector.at(key) = thisVector.at(i);
        thisVector.at(i) = temp;
        
    }
    
    for(int i = 0; i < 10; ++i){
        
        sortedIndexs.push_back(thisVector.at(i).unsortedIndex);
        
    }
    
    return sortedIndexs;
    
}
