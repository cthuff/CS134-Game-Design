


#include "ofMain.h"
#include "emitter.h"

Emitter::Emitter(EnemySystem *enemySys) {
	sys = enemySys;
	lifespan = 3000;    // milliseconds
	started = false;
	lastSpawned = 0;
	rate = 1;    // sprites/sec
	haveImage = false;
	drawable = false;
	width = 50;
	height = 50;
	childWidth = 10;
	childHeight = 10;
}

//  Update the Emitter. If it has been started, spawn new sprites with
//  initial velocity, lifespan, birthtime.
//
void Emitter::update() {
	if (!started) return;

	float time = ofGetElapsedTimeMillis();
	if ((time - lastSpawned) > (1000.0 / rate)) {
		// spawn a new sprite
		Enemy enemy;
		enemy.velocity = ofVec3f(rand() % 500, rand() % 500);
		enemy.lifespan = lifespan;
		enemy.trans = ofVec2f((rand() % ofGetWindowHeight()), 0);
		enemy.birthtime = time;
		enemy.width = childWidth;
		enemy.height = childHeight;
        enemy.image.load("images/enemy.png");
		sys->add(enemy);
		lastSpawned = time;
	}
	sys->update();
}

void Emitter::draw() {
    sys->draw();
}
// Start/Stop the emitter.
//
void Emitter::start() {
	started = true;
	lastSpawned = ofGetElapsedTimeMillis();
}

void Emitter::stop() {
	started = false;
}

void Emitter::setLifespan(float life) {
	lifespan = life;
}

void Emitter::setVelocity(ofVec3f v) {
	velocity = v;
}

void Emitter::setRate(float r) {
	rate = r;
}

float Emitter::maxDistPerFrame() {
	return 75;
}
