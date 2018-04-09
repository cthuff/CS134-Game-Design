//
//  level.cpp
//  ArcadeGame
//
//  Created by Craig Huff on 3/4/18.
//
//  Level to keep track of requirements for each level

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
