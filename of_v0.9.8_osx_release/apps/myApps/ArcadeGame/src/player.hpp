//
//  player.hpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "bullet.hpp"
#include "baseObject.h"


class Player : public BaseObject {

public:
    Player();
    void draw();
    void fire(float, float, vector<Bullet*>*);
    void updateSprite();
    void moveSprite(MoveDir);
    void stopSprite();

    float speed;    // in screenspace coordinates per second  (pixels)
    ofImage image;
    MoveDir moveDir;
    
    ofVec3f start_point;
    ofVec3f finish_point;
};

