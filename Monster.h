//
//  Monster.h
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#ifndef Monster_h
#define Monster_h

#include "Weapon.h"
#include <string>

class Player;

class Monster {
public:
    Monster(const std::string& name, int hp, int acc,
        int xpReward, int gold, int armor, const std::string& weaponName,
        int lowDamage, int highDamage);

    bool isDead();

    int         getXPReward();
    int         getGoldReward();
    std::string getName();
    int         getArmor();

    void attack(Player& player);
    void takeDamage(int damage);
    void displayHitPoints();

private:
    std::string mName;
    int         mHitPoints;
    int         mAccuracy;
    int         mExpReward;
    int         mGold;
    int         mArmor;
    Weapon      mWeapon;
};
#endif /* Monster_h */
*
