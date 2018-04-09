//
//  level.hpp
//  ArcadeGame
//
//  Created by Craig on 3/4/18.
//

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
