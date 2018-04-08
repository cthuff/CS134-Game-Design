//
//  explosion.cpp
//  ArcadeGame
//
//  Created by Craig on 4/3/18.
//

#include "explosion.hpp"
#include "ofMain.h"

Explosion::Explosion() {
    //sys = new ParticleSystem();
    createdSys = true;
    init();
}

Explosion::Explosion(ParticleSystem *s) {
    if (s == NULL)
    {
        cout << "fatal error: null particle system passed to ParticleEmitter()" << endl;
        ofExit();
    }
    sys = s;
    createdSys = false;
    init();
}


void Explosion::init() {
    rate = 1;
    velocity = ofVec3f(0, 20, 0);
    lifespan = 3;
    mass = 1;
    randomLife = false;
    lifeMinMax = ofVec3f(2, 4);
    started = false;
    oneShot = false;
    fired = false;
    lastSpawned = 0;
    radius = 1;
    particleRadius = .1;
    visible = true;
    type = DirectionalEmitter;
    groupSize = 1;
    damping = .99;
    particleColor = ofColor::red;
    position = ofVec3f(0, 0, 0);
}



void Explosion::draw() {
    if (visible) {
        switch (type) {
            case DirectionalEmitter:
                ofDrawSphere(position, radius/10);  // just draw a small sphere for point emitters
                break;
            case SphereEmitter:
            case RadialEmitter:
                ofDrawSphere(position, radius/10);  // just draw a small sphere as a placeholder
                break;
            default:
                break;
        }
    }
    sys->draw();
}
void Explosion::start() {
    started = true;
    lastSpawned = ofGetElapsedTimeMillis();
}

void Explosion::stop() {
    started = false;
    fired = false;
}
void Explosion::update() {
    
    float time = ofGetElapsedTimeMillis();
    
    if (oneShot && started) {
        if (!fired) {
            
            // spawn a new particle(s)
            //
            for (int i = 0; i < groupSize; i++)
                spawn(time);
            
            lastSpawned = time;
        }
        fired = true;
        stop();
    }
    
    else if (((time - lastSpawned) > (1000.0 / rate)) && started) {
        
        // spawn a new particle(s)
        //
        for (int i= 0; i < groupSize; i++)
            spawn(time);
        
        lastSpawned = time;
    }
    
    sys->update();
}

// spawn a single particle.  time is current time of birth
//
void Explosion::spawn(float time) {
    
    ofImage particle;
    
    // set initial velocity and position
    // based on emitter type
    //
    switch (type) {
        case RadialEmitter:
        {
            ofVec3f dir = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
            float speed = velocity.length();
            //particle.velocity = dir.getNormalized() * speed;
            //particle.position.set(position);
        }
            break;
        case SphereEmitter:
            break;
        case DirectionalEmitter:
            //particle.velocity = velocity;
            //particle.position.set(position);
            break;
    }
    
    // other particle attributes
    //
    if (randomLife) {
        //particle.lifespan = ofRandom(lifeMinMax.x, lifeMinMax.y);
    }
    //else particle.lifespan = lifespan;
//    particle.birthtime = time;
//    particle.radius = particleRadius;
//    particle.mass = mass;
//    particle.damping = damping;
//    particle.color = particleColor;
    
    // add to system
    //
    sys->add(particle);
}

