//
//  enemy.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#include "enemy.hpp"

Enemy::Enemy() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1;
    scale.y = 1;
    rot = 0;
    speed = 0;
    bSelected = false;
}

void Enemy::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
}
