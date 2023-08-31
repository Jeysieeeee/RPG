//
//  Spell.h
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#ifndef Spell_h
#define Spell_h

#include "Range.h"
#include <string>
using namespace std;

struct Spell
{
    string      mName;
    Range       mDamageRange;
    int         mMagicPointsRequired;
};

Spell magicMissile{ "Magic Missile", {10, 20}, 5 };
Spell fireball{ "Fireball", {20, 30}, 1 };
Spell shield{ "Shield", {0, 0}, 3 };

#endif /* Spell_h */
