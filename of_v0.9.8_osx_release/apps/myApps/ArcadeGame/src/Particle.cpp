//
//  particle.cpp
//  ArcadeGame
//
//  Created by Craig Huff on 4/8/18.
//  An individual particle to be used in a particle system


#include "Particle.h"


Particle::Particle() {

	// initialize particle with some reasonable values first;
	//
	velocity.set(0, 0, 0);
	acceleration.set(0, 0, 0);
	position.set(0, 0, 0);
	forces.set(0, 0, 0);
	lifespan = 5;
	birthtime = 0;
	radius = .1;
	damping = .99;
	mass = 1;
    int rand = ofRandom(4.99);
    switch ( rand )
    {   case 0 :
            image.load("images/piece1.png");
            break;
        case 1 :
            image.load("images/piece2.png");
            break;
        case 2 :
            image.load("images/piece3.png");
            break;
        case 3 :
            image.load("images/piece4.png");
            break;
        case 4 :
            image.load("images/piece5.png");
            break;
        default  :
            image.load("images/piece1.png");
    }
    
}

void Particle::draw() {
	image.draw(-image.getWidth() / 2.0 + position.x, -image.getHeight() / 2.0 + position.y);
}

// write your own integrator here.. (hint: it's only 3 lines of code)
//
void Particle::integrate() {

	// check for 0 framerate to avoid divide errors
	//
	float framerate = ofGetFrameRate();
	if (framerate < 1.0) return;

	// interval for this step
	//
	float dt = 1.0 / framerate;

	// update position based on velocity
	//
	position += (velocity * dt);

	// update acceleration with accumulated paritcles forces
	// remember :  (f = ma) OR (a = 1/m * f)
	//
	ofVec3f accel = acceleration;    // start with any acceleration already on the particle
	accel += (forces * (1.0 / mass));
	velocity += accel * dt;

	// add a little damping for good measure
	//
	velocity *= damping;

	// clear forces on particle (they get re-added each step)
	//
	forces.set(0, 0, 0);
}

//  return age in seconds
//
float Particle::age() {
	return (ofGetElapsedTimeMillis() - birthtime)/1000.0;
}


