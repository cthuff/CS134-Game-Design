//
//  bullet.hpp
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//

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
    float speed;    // in screenspace coordinates per second  (pixels)
    ofImage image;
	ofSoundPlayer fire;
};