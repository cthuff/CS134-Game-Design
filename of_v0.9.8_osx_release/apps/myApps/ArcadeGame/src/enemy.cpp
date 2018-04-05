//
//  enemy.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
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
    level.levelKills = 10;
    levelFinish = false;
    explosion.load("sounds/explosion.mp3");
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
			tmp = enemies.erase(s);
			s = tmp;
            enemies_killed++;
            explosion.play();
            return true;
		}
		else s++;
	}
    return false;
}


void EnemySystem::update() {

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
        ofSystemAlertDialog("Congratulations! You beat this level!");
        enemies.clear();
        levelFinish = false;
        enemies_killed = 0;
        level.nextLevel();
//        setLevelKills(level_kills + 10);
    }
}

//  Render all the sprites
//
void EnemySystem::draw() {
	if(levelFinish == false)
    for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw();
	}
}
