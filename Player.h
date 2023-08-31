//
//  Player.h
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#ifndef Player_h
#define Player_h
#include "Monster.h"

#include <string>

class Player {
    
public:
    // Constructor.
    Player();

    // Methods
    bool isDead();
    int  getArmor();
    void takeDamage(int damage);
    void createClass();
    bool attack(Monster& monster);
    void levelUp();
    void rest(Monster* monster);
    void viewStats();
    void victory(int xp, int difficultyLevel);
    void gameover();
    void displayHitPoints();
   //void castSpell(Monster& monster);
 
private:
    // Data members.
    std::string      mName;
    std::string      mClassName;
    std::string      mRace;
    int         mAccuracy;
    int         mHitPoints;
    int         mMaxHitPoints;
    int         mExpPoints;
    int         mNextLevelExp;
    int         mLevel;
    int         mArmor;
    int         mGold;
    int         mMagicPoints;
    int         mMaxMagicPoints;
    Weapon      mWeapon;
};


#endif /* Player_h */
