//
//  player.hpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofApp.h"

class Player : public BaseObject {
    
public:
    Player();
    void draw();
    float speed;    // in screenspace coordinates per second  (pixels)
    ofImage image;

};


#endif /* player_hpp */
