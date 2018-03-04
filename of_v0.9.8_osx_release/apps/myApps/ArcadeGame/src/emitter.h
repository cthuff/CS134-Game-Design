#pragma once
//----------------------------------------------------------------------------------
//
// Basic Sprite Emitter Class
//
//

#include "baseObject.h"
#include "enemy.hpp"


//  General purpose Emitter class for emitting sprites
//  This works similar to a Particle emitter
//
class Emitter : public BaseObject {
public:
	Emitter(EnemySystem *);
	void draw();
	void start();
	void stop();
	void setLifespan(float);
	void setVelocity(ofVec3f);
	void setRate(float);
	float maxDistPerFrame();
	void update();
	EnemySystem *sys;
	float rate;
	ofVec3f velocity;
	float lifespan;
	bool started;
	float lastSpawned;
	ofImage childImage;
	ofImage image;
	bool drawable;
	bool haveChildImage;
	bool haveImage;
	float width, height;
	float childWidth, childHeight;
};
