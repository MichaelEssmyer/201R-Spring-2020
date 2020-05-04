//Marcus Garity
//mkgdg4@mail.umkc.edu
//Program 7
//creation date 4/26/2020




#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>

typedef std::map<std::string, std::pair<int,int>> mapper;
typedef std::map<std::string, std::pair<int,int>>::iterator pointer;

mapper readfile();
//reads in file and returns a map


void ScreenPrint(pointer,pointer);
//outputs map to screen.

int main() 
{
 
    try
    {
        mapper ratings = readfile();
        ScreenPrint(ratings.begin(), ratings.end());
    }
    catch (std::runtime_error & excpt)
    {
        std::cout << excpt.what() << std::endl;
    }
  
    std::cout << "Press Enter to Exit Program..."<<std::endl;
    std::cin.get();
}

mapper readfile() 
{
    int rate;
    std::string name;
    mapper ratings;
    int number_of_reviews;
    std::ifstream fin("ratings.txt");
    if (fin.fail())
        throw std::runtime_error("Ratings file not present.Exiting Program");
    
    std::getline(fin, name);

    while (fin.good()) 
    {
        std::getline(fin, name);
        fin >> rate;
        fin.ignore();
        
        if (name == "")
            continue;
        if (ratings.count(name))
        {
            ratings[name].first += 1;
            ratings[name].second += rate;
        }
        else
        {
            ratings[name].first = 1;
            ratings[name].second = rate;
        
        }

    }
    fin.close();
    return ratings;
}

void ScreenPrint(pointer MapPtr,pointer end)
{
   
    while (MapPtr != end)
    {
        std::cout<<std::setw(6) <<std::right<< (*MapPtr).first<<std::left<<":\t"<<std::right<< (*MapPtr).second.first <<" reviewers."<<std::setw(6)<<"     Average of "<< (*MapPtr).second.second/ double( (*MapPtr).second.first) <<"/5"<< std::endl;
        MapPtr++;
    }



}

