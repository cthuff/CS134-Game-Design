#pragma once

#include "baseObject.h"
#include "enemy.hpp"

//  Emmiter that will handle creating and launching enemies.

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
};
