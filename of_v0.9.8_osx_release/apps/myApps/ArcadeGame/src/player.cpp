//
//  player.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#include "player.hpp"



void Sprite::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
}



