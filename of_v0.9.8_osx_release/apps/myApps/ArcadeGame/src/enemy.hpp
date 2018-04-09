//
//  enemy.hpp
//  ArcadeGame
//
//  Created by Craig Huff on 2/21/18.
//

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "baseObject.h"
#include "level.hpp"
#include "ParticleEmitter.h"

class Enemy : public BaseObject {
    
public:
    Enemy();
	float age();
    void draw();
    float speed;    // in screenspace coordinates per second  (pixels)
    ofImage image;
	ofVec3f velocity; // in pixels/sec
	float birthtime; // elapsed time in ms
	float lifespan;  //  time in ms
	bool haveImage;
	float width, height;
};


// The enemy system keeps track of all the enemies that currently exist in the game
//
class EnemySystem {
public:
    EnemySystem();
	void add(Enemy);
	void remove(int);
	void update();
	bool removeNear(ofVec3f point, float dist);
	void draw();
    void reset();
    void removeAll();
	vector<Enemy> enemies;
    float enemies_killed;
    float level_kills;
    int score;
    bool levelFinish;
    ofSoundPlayer explosion;
    ParticleEmitter emitter;
    Level level;
};
