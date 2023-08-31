//
//  Random.cpp
//  RPG
//
//  Created by Jean Carla Guarra on 8/29/23.
//

#include "Random.h"
#include <stdio.h>
#include <cstdlib>

int Random(Range r) {
      return r.mLow + rand() % ((r.mHigh + 1) - r.mLow);
}

int Random(int low, int high) {
      return low + rand() % ((high + 1) - low);
}
