//
//  baseObject.h
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//

#pragma once
#include "ofMain.h"


typedef enum { MoveStop, MoveLeft, MoveRight, MoveUp, MoveDown } MoveDir;

class BaseObject {
public:
    BaseObject();
    ofVec2f trans, scale;
    float   rot;
    bool    bSelected;
    void    setPosition(const ofVec3f &);
};
