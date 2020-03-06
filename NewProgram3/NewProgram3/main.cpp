//
//  main.cpp
//  NewProgram3
//
//  Created by Davith Lon on 2/26/20.
//  Copyright © 2020 Davith Lon. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include "functions.hpp"
#include "city.hpp"

using namespace std;

int main() {
    
    std::ifstream inFS;
    const int ARRAY_SIZE = 10;
    std::string firstName[ARRAY_SIZE];
    std::string lastName[ARRAY_SIZE];
    std::string cityName[ARRAY_SIZE];
    std::string stateName[ARRAY_SIZE];
    double GPA[ARRAY_SIZE];
    int studentId[ARRAY_SIZE];
    int selection;
    
    std::cout << "Opening File: Student_Info.txt ..." << std::endl;
    inFS.open("Student_Info.txt");

    if(!inFS.is_open()){

        std::cout << "Error, Student_Info.txt could not open. " << std::endl;
        std::cout << "Exiting the program. " << std::endl;

        return -1;
    }
    else{
        std::cout << "Student_Info.txt was succesfully opened!" << std::endl << std::endl;
    }
    
    for (int i = 0; i < ARRAY_SIZE; ++i){
        inFS >> studentId[i];
        inFS >> firstName[i];
        inFS >> lastName[i];
        inFS >> cityName[i];
        inFS >> stateName[i];
        inFS >> GPA[i];
    }

    inFS.close();

    do{
    menu();
    std::cin >> selection;

    while(selection != 1 && selection != 2 && selection != 3 && selection != 4){
        std::cout << "Sorry that was an invalid input." << std::endl;
        menu();
        std::cin >> selection;

    }

        switch (selection) {
            case 1:
                display(studentId, firstName, lastName, cityName, stateName, GPA, ARRAY_SIZE);
                break;
            case 2:
                display_Info(studentId, firstName, lastName, cityName, stateName, GPA, ARRAY_SIZE);
                break;
            case 3:
                display_Info(studentId, firstName, lastName, cityName, stateName, GPA, ARRAY_SIZE);
                count_city(cityName, stateName, ARRAY_SIZE);
                break;
            default:
                break;
        }

    }while(selection != 4);

    std::cout << "Closing the Program! Good Bye!" << std::endl;
    
    return 0;
}
