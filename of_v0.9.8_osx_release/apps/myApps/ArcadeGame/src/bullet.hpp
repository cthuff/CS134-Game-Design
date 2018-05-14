//
//  bullet.hpp
//  ArcadeGame
//
//  Created by Craig Huff on 2/26/18.
//
//  Creates a new object that the player will fire at the enemies

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "baseObject.h"

class Bullet : public BaseObject {
    
public:
    Bullet() {
        trans.x = 0;
        trans.y = 0;
        scale.x = 1.0;
        scale.y = 1.0;
        rot = 0;
        speed = 0;
        bSelected = false;
        fire.load("sounds/pew.mp3");
    }
    void draw() {
        ofSetColor(255, 255, 255, 255);
        image.draw(trans.x - 10, trans.y - 100);
    }
	void sound()
    {
        fire.play();
    }
	void kill()
    {
        trans.set(0, -10);
    }   
    float speed;
        ofImage image;
        ofSoundPlayer fire;
};
