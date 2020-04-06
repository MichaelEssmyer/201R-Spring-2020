//
//  tile.hpp
//  Program 4 Conner Keiter
//
//  Created by Conner Keiter on 3/16/20.
//  Copyright © 2020 Conner Keiter. All rights reserved.
//

#ifndef tile_hpp
#define tile_hpp

#include <stdio.h>
//each tile has a mark and a bool value of if its taken
struct Tile {
    char mark='_';
    bool available=true;
};
#endif /* tile_hpp */
