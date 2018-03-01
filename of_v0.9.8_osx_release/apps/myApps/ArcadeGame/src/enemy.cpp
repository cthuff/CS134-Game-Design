//
//  enemy.cpp
//  ArcadeGame
//
//  Created by Craig on 2/21/18.
//

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

float Enemy::age() {
	return (ofGetElapsedTimeMillis() - birthtime);
}

void EnemySystem::add(Enemy s) {
	enemies.push_back(s);
}

void EnemySystem::remove(int i) {
	enemies.erase(enemies.begin() + i);
}

void EnemySystem::removeNear(ofVec3f point, float dist) {
	vector<Enemy>::iterator s = enemies.begin();
	vector<Enemy>::iterator tmp;

	while (s != enemies.end()) {
		ofVec3f v = s->trans - point;
		if (v.length() < dist) {
			tmp = enemies.erase(s);
			s = tmp;
		}
		else s++;
	}
}


void EnemySystem::update() {

	if (enemies.size() == 0) return;
	vector<Enemy>::iterator s = enemies.begin();
	vector<Enemy>::iterator tmp;


	while (s != enemies.end()) {
		if (s->lifespan != -1 && s->age() > s->lifespan) {
			//			cout << "deleting Enemy: " << s->name << endl;
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
}

//  Render all the sprites
//
void EnemySystem::draw() {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw();
	}
}