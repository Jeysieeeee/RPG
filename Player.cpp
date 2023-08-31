//
//  Player.cpp
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#include <iostream>
#include "Player.h"
#include "Random.h"
#include "Spell.h"
#include <string>
using namespace std;

Player::Player()
{
    mName         = "Default";
    mClassName    = "Default";
    mRace         = "Default";
    mAccuracy     = 0;
    mHitPoints    = 0;
    mMaxHitPoints = 0;
    mExpPoints    = 0;
    mNextLevelExp = 0;
    mLevel        = 0;
    mArmor        = 0;
    mMagicPoints  = 20;
    mWeapon.mName = "Default Weapon Name";
    mWeapon.mDamageRange.mLow  = 0;
    mWeapon.mDamageRange.mHigh = 0;
}

bool Player::isDead()
{
    return mHitPoints <= 0;
}

int Player::getArmor()
{
    return mArmor;
}

void Player::takeDamage(int damage)
{
    mHitPoints -= damage;
}

void Player::createClass() {
    cout << "CHARACTER CLASS GENERATION" << endl;
    cout << "============================" << endl;
    
    // Input character's name.
    cout << "Enter your character's name: ";
    getline(cin, mName);
    
    // Character selection.
    cout << "Please select a character class number..."<< endl;
    cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
    int characterNum = 1;
    cin >> characterNum;
    
    cout << "Please select a character race number..." << endl;
    cout << "1) Dwarf 2) Human 3) Elf 4) Halfling : ";
    int raceNum = 1;
    cin >> raceNum;
    
    switch( characterNum ) {
        case 1:  // Fighter
            mClassName    = "Fighter";
            mAccuracy     = 10;
            mHitPoints    = 20;
            mMaxHitPoints = 20;
            mExpPoints    = 0;
            mNextLevelExp = 1000;
            mLevel        = 1;
            mArmor        = 4;
            mMagicPoints  = 20;
            mWeapon.mName = "Long Sword";
            mWeapon.mDamageRange.mLow  = 1;
            mWeapon.mDamageRange.mHigh = 8;
            break;
        case 2:  // Wizard
            mClassName    = "Wizard";
            mAccuracy     = 5;
            mHitPoints    = 10;
            mMaxHitPoints = 10;
            mExpPoints    = 0;
            mNextLevelExp = 1000;
            mLevel        = 1;
            mArmor        = 1;
            mMagicPoints  = 5;
            mWeapon.mName = "Staff";
            mWeapon.mDamageRange.mLow  = 1;
            mWeapon.mDamageRange.mHigh = 4;
            break;
        case 3:  // Cleric
            mClassName    = "Cleric";
            mAccuracy     = 8;
            mHitPoints    = 15;
            mMaxHitPoints = 15;
            mExpPoints    = 0;
            mNextLevelExp = 1000;
            mLevel        = 1;
            mArmor        = 3;
            mMagicPoints  = 3;
            mWeapon.mName = "Flail";
            mWeapon.mDamageRange.mLow  = 1;
            mWeapon.mDamageRange.mHigh = 6;
            break;
        default: // Thief
            mClassName    = "Thief";
            mAccuracy     = 7;
            mHitPoints    = 12;
            mMaxHitPoints = 12;
            mExpPoints    = 0;
            mNextLevelExp = 1000;
            mLevel        = 1;
            mArmor        = 2;
            mMagicPoints  = 2;
            mWeapon.mName = "Short Sword";
            mWeapon.mDamageRange.mLow  = 1;
            mWeapon.mDamageRange.mHigh = 6;
            break;
    }
    
    switch (raceNum) {
        case 1: // Dwarf
            mRace = "Dwarf";
            mAccuracy -= 2; // Decrease accuracy for dwarves
            mHitPoints += 5; // Increase hit points for dwarves
            break;
        case 2: // Human
            mRace = "Human";
            // No statistical pros or cons for humans
            break;
        case 3:
            mRace = "Elf";
            mAccuracy += 2; // Increase accuracy for elves
            mHitPoints -= 3; // Decrease hit points for elves
            break;
        case 4:
            mRace = "Halfling";
            mAccuracy += 1; // Increase accuracy for halflings
            mHitPoints -= 2; // Decrease hit points for halflings
            break;
    }
}

bool Player::attack(Monster& monster) {
    Spell spell;
    // Combat is turned based: display an options menu.  You can,
    // of course, extend this to let the player use an item,
    // cast a spell, and so on.
    int selection = 1;
    cout << "1) Attack, 2) Cast Spell, 3) Run: ";
    cin >> selection;
    cout << endl;
    
    switch( selection ) {
        case 1:
            cout << "You attack an " << monster.getName()
            << " with a " << mWeapon.mName << endl;
            
            if( Random(0, 20) < mAccuracy )
            {
                int damage = Random(mWeapon.mDamageRange);
                
                int totalDamage = damage - monster.getArmor();
                
                if( totalDamage <= 0 )
                {
                    cout << "Your attack failed to penetrate "
                    << "the armor." << endl;
                }
                else
                {
                    cout << "You attack for " << totalDamage
                    << " damage!" << endl;
                    
                    // Subtract from monster's hitpoints.
                    monster.takeDamage(totalDamage);
                }
            }
            else {
                cout << "You miss!" << endl;
            }
            cout << endl;
            break;
            
        case 2:
            cout << "Available Spells:" << endl;
            cout << "1. Magic Missile" << endl;
            cout << "2. Fireball" << endl;
            cout << "3. Shield" << endl;
            
            int spellChoice;
            cin >> spellChoice;
            
            switch (spellChoice) {
                case 1:
                    if (mMagicPoints < magicMissile.mMagicPointsRequired) {
                        cout << "Not enough magic points to cast Magic Missile!" << endl;
                    } else {
                        cout << "Casting Magic Missile!" << endl;
                        mMagicPoints -= magicMissile.mMagicPointsRequired;
                        int damage = Random(magicMissile.mDamageRange);
                        damage -= monster.getArmor();
                        damage = max(0, damage);
                        monster.takeDamage(damage);
                        cout << "The monster's hitpoints decreased by " << damage << endl;
                    }
                    break;
                    
                case 2:
                    if (mMagicPoints < fireball.mMagicPointsRequired) {
                        cout << "Not enough magic points to cast Fireball!" << endl;
                    } else {
                        cout << "Casting Fireball!" << endl;
                        mMagicPoints -= fireball.mMagicPointsRequired;
                        int damage = Random(fireball.mDamageRange);
                        damage -=  monster.getArmor();
                        damage = max(0, damage);
                        monster.takeDamage(damage);
                    }
                    break;
                    
                case 3:
                    if (mMagicPoints < shield.mMagicPointsRequired) {
                        cout << "Not enough magic points to cast Shield!" << endl;
                    } else {
                        cout << "Casting Shield!" << endl;
                        mMagicPoints -= shield.mMagicPointsRequired;
                      //TODO: Implementation of shield.
                        }
                    
                    break;
                    
                default:
                    cout << "Invalid spell choice!" << endl;
                    break;
            }
            break;
            
        case 3:
            // 25 % chance of being able to run.
            int roll = Random(1, 4);
            
            if( roll == 1 )
            {
                cout << "You run away!" << endl;
                return true;///<Return out of the function.
            }
            else
            {
                cout << "You could not escape!" << endl;
                break;
            }
    }
    
    return false;
}

void Player::levelUp() {
    if (mExpPoints >= mNextLevelExp) {
        cout << "You gained a level!" << endl;
        
        // Increment level.
        mLevel++;
        
        // Set experience points required for next level.
        mNextLevelExp = mLevel * mLevel * 1000;
        
        // Increase stats randomly.
        mAccuracy     += Random(1, 3);
        mMaxHitPoints += Random(2, 6);
        mArmor        += Random(1, 2);
        
        // Increase magic points based on character class.
        if (mClassName == "fighter") {
            mMagicPoints += Random(1, 2);
        } else if (mClassName == "wizard") {
            mMagicPoints += Random(3, 6);
        }
        
        // Ensure mMagicPoints does not exceed mMaxMagicPoints.
        if (mMagicPoints > mMaxMagicPoints) {
            mMagicPoints = mMaxMagicPoints;
        }
        
        // Give player full hit points when they level up.
        mHitPoints = mMaxHitPoints;
    }
}


//void Player::rest(Monster* monster) {
//
//    mHitPoints = mMaxHitPoints;
//    int chance = rand() % 100 + 1;
//    if (chance <= 100) {
//    cout << "Resting..." << endl;
//      // Enemy encounter occurs
//      cout << "You were attacked by an enemy while resting!" << endl;
//      cout << "What do you want to do?" << endl;
//      cout << "1. Fight" << endl;
//      cout << "2. Flee" << endl;
//
//        int choice;
//        cin >> choice;
//        if (choice == 1) {
//            cout << "You attack an " << monster->getName()
//            << " with a " << mWeapon.mName<< endl;
//
//            if( Random(0, 20) < mAccuracy ) {
//                int damage = Random(mWeapon.mDamageRange);
//
//                int totalDamage = damage - monster->getArmor();
//
//                if( totalDamage <= 0 ) {
//                    cout << "Your attack failed to penetrate "
//                    << "the armor." << endl;
//                } else {
//                    cout << "You attack for " << totalDamage
//                    << " damage!" << endl;
//
//                    // Subtract from monster's hitpoints.
//                    monster->takeDamage(totalDamage);
//                }
//            } else {
//                cout << "You miss!" << endl;
//            }
//            cout << endl;
//
//        } else if (choice == 2) {
//            int roll = Random(1, 4);
//
//            if( roll == 1 ) {
//                cout << "You run away!" << endl;
//            } else {
//                cout << "You could not escape!" << endl;
//            }
//        } else {
//            rest(monster);
//        }
//      }
//
//}

void Player::viewStats() {
    cout << "PLAYER STATS" << endl;
    cout << "============" << endl;
    cout << endl;
    
    cout << "Name            = " << mName         << endl;
    cout << "Class           = " << mClassName    << endl;
    cout << "Race            = " << mRace         << endl;
    cout << "Accuracy        = " << mAccuracy     << endl;
    cout << "Hitpoints       = " << mHitPoints    << endl;
    cout << "MaxHitpoints    = " << mMaxHitPoints << endl;
    cout << "XP              = " << mExpPoints    << endl;
    cout << "XP for Next Lvl = " << mNextLevelExp << endl;
    cout << "Level           = " << mLevel        << endl;
    cout << "Armor           = " << mArmor        << endl;
    cout << "Weapon Name     = " << mWeapon.mName << endl;
    cout << "Gold Collected  = " << mGold         << endl;
    cout << "Magic Points    = " << mMagicPoints  << endl;
    cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" <<
    mWeapon.mDamageRange.mHigh << endl;
    
    cout << endl;
    cout << "END PLAYER STATS" << endl;
    cout << "================" << endl;
    cout << endl;
}

int generateGoldReward (int difficultyLevel){
    int minGold = difficultyLevel * 10;
    int maxGold = difficultyLevel * 20;
    int goldReward = Random( minGold, maxGold);
    
    return goldReward;
}

void Player::victory(int xp, int difficultyLevel) {
    int goldReward = generateGoldReward(difficultyLevel);
    
    cout << "You won the battle!" << endl;
    cout << "You win " << xp
    << " experience points and " << goldReward << " gold!" << endl ;
    
    mExpPoints += xp;
    mGold = goldReward;
}

void Player::gameover()
{
    cout << "You died in battle..." << endl;
    cout << endl;
    cout << "================================" << endl;
    cout << "GAME OVER!" << endl;
    cout << "================================" << endl;
    cout << "Press 'q' to quit: ";
    char q = 'q';
    cin >> q;
    cout << endl;
}

void Player::displayHitPoints()
{
    cout << mName << "'s hitpoints = " << mHitPoints << endl;
}

