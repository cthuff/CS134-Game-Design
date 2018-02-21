#pragma once

#include "ofMain.h"
#include "player.hpp"

typedef enum { MoveStop, MoveLeft, MoveRight, MoveUp, MoveDown } MoveDir;

class BaseObject {
public:
    ofVec2f trans, scale;
    float   rot;
    bool    bSelected;
};

class Sprite : public BaseObject {
    
public:
    Sprite();
    void draw();
    float speed;    // in screenspace coordinates per second  (pixels)
    ofImage image;
    
};


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
    void updateSprite();
    void moveSprite(MoveDir);
    
    void updateBullet();
    void moveBullet(MoveDir);
    
    void stopSprite();
    void startAccel();
    void stopAccel();
    float modulateAccel(float);
    
    ofSoundPlayer explosion;
    ofSoundPlayer fire;
    ofSoundPlayer mySound;
    
    Sprite sprite;
    Sprite enemy;
    Sprite bullet;
    ofVec3f start_point;
    ofVec3f finish_point;
    float start_time;
    float finish_time;
    ofVec3f mouse_last;
    MoveDir moveDir;
    bool accel;
    ofVec3f startAccelPoint;
    ofImage background;
    
};

