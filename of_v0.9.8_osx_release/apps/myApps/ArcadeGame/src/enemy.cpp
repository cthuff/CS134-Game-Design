//
//  enemy.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

#include "ofMain.h"
#include "enemy.hpp"

Enemy::Enemy() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1;
    scale.y = 1;
    rot = 0;
    speed = 0;
    bSelected = false;
	velocity = ofVec3f(0, 0, 0);
	lifespan = -1;      
	birthtime = 0;
}

void Enemy::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
}

EnemySystem::EnemySystem() {
    enemies_killed = 0;
    levelFinish == false;
    explosion.load("sounds/explosion.mp3");
}

float Enemy::age() {
	return (ofGetElapsedTimeMillis() - birthtime);
}

void EnemySystem::add(Enemy s) {
	enemies.push_back(s);
}

void EnemySystem::remove(int i) {
	enemies.erase(enemies.begin() + i);
    enemies_killed++;
}

bool EnemySystem::removeNear(ofVec3f point, float dist) {
	vector<Enemy>::iterator s = enemies.begin();
	vector<Enemy>::iterator tmp;

	while (s != enemies.end()) {
		ofVec3f v = s->trans - point;
		if (v.length() < dist) {
			tmp = enemies.erase(s);
			s = tmp;
            enemies_killed++;
//            cout << enemies_killed << endl;
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
    
    if (enemies_killed >= 10)
    {
        levelFinish = true;
        ofSystemAlertDialog("Congratulations! You won!");
        enemies.clear();
        levelFinish = false;
        enemies_killed = 0;
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
