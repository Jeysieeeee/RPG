//
//  Map.h
//  Activity_RPG_Games
//
//  Created by Jean Carla Guarra on 8/25/23.
//

#ifndef Map_h
#define Map_h

#include "Weapon.h"
#include "Monster.h"
#include <iostream>
#include <string>


class Map {
public:
    Map();
    int  getPlayerXPos();
    int  getPlayerYPos();
    void movePlayer();
    Monster* checkRandomEncounter();
    void printPlayerPos();
private:
    int mPlayerXPos;
    int mPlayerYPos;
};


#endif /* Map_h */
