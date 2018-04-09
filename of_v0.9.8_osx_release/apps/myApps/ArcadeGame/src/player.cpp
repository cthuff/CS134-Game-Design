//
//  player.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//  This is the turret that the player controls.
//  It will fire bullets at the enemies as the come on the screen.
//

#include "player.hpp"

Player::Player() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1;
    scale.y = 1;
    rot = 0;
    speed = 0;
    health = 5;
    bSelected = false;
}

void Player::draw() {
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
    //Stops the player from moving off the screen
    if(trans.x <= 69)
        trans.x = 69;
    else if (trans.x >= ofGetWindowWidth() - 69)
        trans.x = ofGetWindowWidth() - 69;
        
}

// Creates a new bullet object and adds to the vector of already exiting bullets
void Player::fire(float x, float y, vector<Bullet*>* bullets) {
    Bullet* newBullet = new Bullet;
    newBullet->image.load("images/bullet.png");
    newBullet->trans.x = x;
    newBullet->trans.y = y;
	newBullet->sound();
    bullets->push_back(newBullet);
}
// Handles the directions the user can move the sprite
// I disabled up and down, making it only able to move right and left at the bottom of the window.
//
void Player::updateSprite() {

    float dist = speed * 3 / ofGetFrameRate();
    ofVec3f dir;
   
    {
        switch (moveDir)
        {
            case MoveUp:
                dir = ofVec3f(0, -dist, 0);
                break;
            case MoveDown:
                dir = ofVec3f(0, dist, 0);
            case MoveLeft:
                dir = ofVec3f(-dist, 0, 0);
                break;
            case MoveRight:
                dir = ofVec3f(dist, 0, 0);
                break;
            case MoveStop:
                dir = ofVec3f(0, 0, 0);
                break;
        }
    }
    trans += dir;
    start_point += dir;
}

void Player::moveSprite(MoveDir dir) {
    moveDir = dir;
}

void Player::stopSprite() {
    moveDir = MoveStop;
}

void Player::checkCollision(Emitter* emitter) {
    if(emitter->sys->removeNear(trans, emitter->maxDistPerFrame()) )
    {
        health--;
        emitter->sys->enemies_killed--;
        emitter->sys->score--;
    }
}

