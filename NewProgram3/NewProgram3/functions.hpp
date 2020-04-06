//
//  functions.hpp
//  NewProgram3
//
//  Created by Davith Lon on 2/26/20.
//  Copyright © 2020 Davith Lon. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <string>
#include "city.hpp"



void menu(void);
void display(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[],int size);
void display_Info(int ID[], std::string first[], std::string last[], std::string city[], std::string state[], double GPA[], int size);
void count_city(std::string city[], std::string state[],int size);
std::vector<int> createVectorOfSortedCityIndices(std::vector<city> thisVector);


#endif /* functions_hpp */
