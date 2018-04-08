//
//  baseObject.h
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//

#pragma once

typedef enum { MoveStop, MoveLeft, MoveRight, MoveUp, MoveDown } MoveDir;

class BaseObject {
public:
    ofVec2f trans, scale;
    float   rot;
    bool    bSelected;
    void    setPosition(ofVec3f &);
};

