//
//  bullet.cpp
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//

#include "player.hpp"

Bullet::Bullet() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1.0;
    scale.y = 1.0;
    rot = 0;
    speed = 0;
    bSelected = false;
	fire.load("sounds/pew.mp3");
}

void Bullet::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(trans.x - 10, trans.y - 100); 
	
}

void Bullet::sound()
{
	fire.play();
}

void Bullet::kill()
{
    trans.set(0, -10);
	image.clear();
}
