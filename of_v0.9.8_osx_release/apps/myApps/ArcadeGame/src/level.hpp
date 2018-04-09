//
//  level.hpp
//  ArcadeGame
//
//  Created by Craig Huff on 3/4/18.
//
//  Keeps track of which level the game is currently on (there are only 5)

#pragma once

#include <stdio.h>
#include "ofMain.h"


class Level {

public:
    Level();
    void nextLevel();
    void finalLevel();
    int currentLevel;
    int levelKills;
};
