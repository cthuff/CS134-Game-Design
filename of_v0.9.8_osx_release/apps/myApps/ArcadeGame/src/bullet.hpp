//
//  bullet.hpp
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//
//  Creates a new object that the player will fire at the enemies

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "baseObject.h"

class Bullet : public BaseObject {
    
public:
    Bullet();
    void draw();
	void sound();
	void kill();
    float speed;
    ofImage image;
	ofSoundPlayer fire;
};
