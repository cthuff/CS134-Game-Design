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
    image.draw(trans.x - 10, trans.y - 100);
}
//The bullet plays the sound when fired, not the turret
void Bullet::sound()
{
	fire.play();
}
//Moves the bullet to where it will be destoryed on the next frame.
void Bullet::kill()
{
    trans.set(0, -10);
}
