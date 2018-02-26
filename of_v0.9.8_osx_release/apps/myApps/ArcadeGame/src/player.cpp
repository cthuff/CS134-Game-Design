//
//  player.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#include "player.hpp"

Player::Player() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1;
    scale.y = 1;
    rot = 0;
    speed = 0;
    bSelected = false;
}

void Player::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
    if(trans.x <= 69)
        trans.x = 69;
    else if (trans.x >= ofGetWindowWidth() - 69)
        trans.x = ofGetWindowWidth() - 69;
        
}

int Player::getAvgX() {
    cout << trans.x << endl;
    return trans.x;
}

int Player::getAvgY() {
    cout << trans.y << endl;
    return trans.y;
}

void Player::fire(float x, float y, vector<Bullet*>* bullets) {
    Bullet* newBullet = new Bullet;
    newBullet->image.load("images/bullet.png");
    newBullet->trans.x = x;
    newBullet->trans.y = y;
    bullets->push_back(newBullet);
}

void Player::updateSprite() {
    
    //
    // calculate distance to travel for this update
    //
    float dist = speed * 3.5 / ofGetFrameRate();
    ofVec3f dir;
    ofRectangle r = ofGetWindowRect();
    
    //
    //  if the accelerator modifer key is pressed, accelerate and
    //  deacclerate sprite from starting position to window edge
    //
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
