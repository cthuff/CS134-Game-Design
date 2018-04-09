//
//  level.cpp
//  ArcadeGame
//
//  Created by Craig on 3/4/18.
//

#include "level.hpp"

Level::Level() {
    currentLevel = 0;
    levelKills = 10;
}

void Level::nextLevel(){
    levelKills = levelKills + 10;
    currentLevel = currentLevel + 1;
}

void Level::finalLevel(){
    currentLevel = 5;
}
