//
//  emitter.cpp
//  ArcadeGame
//
//  Created by Craig on 2/26/18.
//
//  The emitter will handle spawning all of the enemies
//  and keeping track of where they are

#include "ofMain.h"
#include "emitter.h"

Emitter::Emitter(EnemySystem *enemySys) {
	sys = enemySys;
	lifespan = 3000;    // milliseconds
	started = false;
	lastSpawned = 0;
	rate = 1;    // sprites/sec
}

//  Update the Emitter. If it has been started, spawn new enemies with
//  initial velocity, lifespan, birthtime.
//
void Emitter::update() {
    if(sys->levelFinish == true)
        started = false;
    else
        started = true;
    
    if (!started) return;

	float time = ofGetElapsedTimeMillis();
	if ((time - lastSpawned) > (1000.0 / rate)) {
		// spawn a new enemy
        //
		Enemy enemy;
        //chooses a random velocity in the x direction from -500 to 500
        //chooses a random velocity in the y direction from 0 to 500
        //
		enemy.velocity = ofVec3f(rand() % 500 - rand() % 500, rand() % 500);
		enemy.lifespan = lifespan;
        
        //select a random x position to start at, and 0 for the y position
        //
		enemy.trans = ofVec2f((rand() % ofGetWindowHeight()), 0);
        
		enemy.birthtime = time;
        enemy.image.load("images/enemy.png");
		sys->add(enemy);
		lastSpawned = time;
    }
    
	sys->update();
}

//tells the EnemySystem to draw all of its sprites
//
void Emitter::draw() {
    sys->draw();
}

//Starts the emitter
//
void Emitter::start() {
	started = true;
	lastSpawned = ofGetElapsedTimeMillis();
}

void Emitter::stop() {
	started = false;
}

//Uses this to see if a sprite has been along for too long
//
void Emitter::setLifespan(float life) {
	lifespan = life;
}

//Sets the starting velocity of the emitter
//
void Emitter::setVelocity(ofVec3f v) {
	velocity = v;
}

//Sets the rate of which enemies are spawned
//
void Emitter::setRate(float r) {
	rate = r;
}
//The most amount of distance that can be covered in one frame by a sprite
//**I found that hard coding this made my coollision work more accuratly**
//
float Emitter::maxDistPerFrame() {
	return 75;
}
