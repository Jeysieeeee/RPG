//
//  Weapon.h
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#ifndef Weapon_h
#define Weapon_h

#include "Range.h"
#include <string>

struct Weapon {
    std::string mName;
    Range       mDamageRange;
};

#endif /* Weapon_h */
