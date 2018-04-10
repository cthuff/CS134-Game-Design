//
//  enemy.cpp
//  ArcadeGame
//
//  Created by Craig Huff on 2/21/18.
//
//  the enemy that the player will be trying to destroy

#include "ofMain.h"
#include "enemy.hpp"

Enemy::Enemy() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1;
    scale.y = 1;
    rot = 27;
    speed = 0;
    bSelected = false;
	velocity = ofVec3f(0, 0, 0);
	lifespan = -1;      
	birthtime = 0;
}

void Enemy::draw() {
    
    ofSetColor(255, 255, 255, 255);
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
}

//Initializes the two conditions to finish the game, and loads the sound for enemy collisions
//
EnemySystem::EnemySystem() {
    
    enemies_killed = 0;
    score = 0;
    level.levelKills = 10;
    levelFinish = false;
    explosion.load("sounds/explosion.mp3");
    
    emitter.setOneShot(true);
    emitter.setEmitterType(RadialEmitter);
    emitter.setGroupSize(6);
    emitter.setLifespan(1);
    emitter.setVelocity(ofVec3f(100, 0, 0));
    emitter.setParticleRadius(10);
    
}

//Track the age of the enemy.
//If the age is too great, the enemy will undraw itself
//
float Enemy::age() {
	return (ofGetElapsedTimeMillis() - birthtime);
}

//Adds new enemies to the vector
//
void EnemySystem::add(Enemy s) {
	enemies.push_back(s);
}

void EnemySystem::reset()
{
    removeAll();
    score = 0;
    level_kills = 10;
    enemies_killed = 0;
    level.currentLevel = 1;
}

void EnemySystem::removeAll() {
    vector<Enemy>::iterator s = enemies.begin();
    while (s != enemies.end())
        enemies.erase(s);
}

//Removes specific enemies
//
void EnemySystem::remove(int i) {
	enemies.erase(enemies.begin() + i);
    enemies_killed++;
}

//Uses the Vector point to determine if other objects are nearby.
//If there are other objects, then we will remove the ship from the EnemySystem.
//
bool EnemySystem::removeNear(ofVec3f point, float dist) {
	vector<Enemy>::iterator s = enemies.begin();
	vector<Enemy>::iterator tmp;
    
	while (s != enemies.end()) {
		ofVec3f v = s->trans - point;
        //removes enimies that share a position with the bullet
        if (v.length() < dist) {
            emitter.trans = point;
            emitter.position = emitter.trans;
            emitter.update();
            //cout << emitter.position << endl;
            tmp = enemies.erase(s);
			s = tmp;
            enemies_killed++;
            score++;
            emitter.start();
            explosion.play();
            return true;
		}
		else s++;
	}
    return false;
}


void EnemySystem::update() {
    
    emitter.update();
    
	if (enemies.size() == 0) return;
	vector<Enemy>::iterator s = enemies.begin();
	vector<Enemy>::iterator tmp;

    //Destroy enemies that have lived past their life
	while (s != enemies.end()) {
		if (s->lifespan != -1 && s->age() > s->lifespan) {
			tmp = enemies.erase(s);
			s = tmp;
		}
		else s++;
	}

	//  Move Enemy
	//
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].trans += enemies[i].velocity / ofGetFrameRate();
	}
    
    //Win condtion (I'm tempted to change this to a higher number)
    //*This is how I could implement more levels
    //
    
    if (enemies_killed >= level.levelKills)
    {
        levelFinish = true;
        level.nextLevel();
        if (level.currentLevel == 6)
        {
            ofSystemAlertDialog("Congratulations! You Won! Press okay to start again");
            removeAll();
            levelFinish = false;
            enemies_killed = 0;
            level.levelKills = 10;
            level.currentLevel = 0;
        }
        else {
            ofSystemAlertDialog("You beat this level! Continue....");
            removeAll();
            levelFinish = false;
            enemies_killed = 0;
        }
    }
    
}

//  Render all the sprites
//
void EnemySystem::draw() {
	if(levelFinish == false)
    for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw();
	}
    emitter.draw();
}
