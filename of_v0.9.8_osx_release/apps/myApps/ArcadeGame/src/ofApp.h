#pragma once

#include "ofMain.h"
#include "player.hpp"
#include "enemy.hpp"
#include "bullet.hpp"
#include "baseObject.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void updateBullet(Bullet b);
    void moveBullet(MoveDir);
    
    
    ofSoundPlayer explosion;
    ofSoundPlayer mySound;
    
    Player sprite;
    Bullet bullet;
    Enemy enemy;
    
    
    float start_time;
    float finish_time;
    ofVec3f mouse_last;
    
    MoveDir bulletDir = MoveUp;
    
   
    ofImage background;
    
    vector<Bullet*>* bullets;
};

