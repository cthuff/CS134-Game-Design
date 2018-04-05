//
//  enemy.hpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "baseObject.h"
#include "level.hpp"

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
    //void setLevelKills(int num);
	bool removeNear(ofVec3f point, float dist);
	void draw();
	vector<Enemy> enemies;
    float enemies_killed;
    float level_kills;
    bool levelFinish;
    ofSoundPlayer explosion;
    Level level;
};
