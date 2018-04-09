//
//  baseObject.cpp
//  ArcadeGame
//
//  Created by Craig Huff on 4/8/18.
//

#pragma once
#include "baseObject.h"
#include "ofMain.h"

//  Base class for any object that needs a transform.
//
BaseObject::BaseObject() {
	trans = ofVec3f(0, 0, 0);
	scale = ofVec3f(1, 1, 1);
	rot = 0;
}

void BaseObject::setPosition(const ofVec3f & pos) {
	trans = pos;
}
