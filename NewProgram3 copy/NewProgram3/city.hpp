//
//  city.hpp
//  NewProgram3
//
//  Created by Davith Lon on 3/4/20.
//  Copyright © 2020 Davith Lon. All rights reserved.
//

#ifndef city_hpp
#define city_hpp

#include <iostream>
#include <string>


class city{
    
public:
    city(std::string name, int index);
    std::string cityName;
    int unsortedIndex;
    
};

#endif /* city_hpp */
