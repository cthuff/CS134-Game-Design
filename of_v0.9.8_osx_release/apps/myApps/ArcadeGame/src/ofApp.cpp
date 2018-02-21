#include "ofApp.h"
//----------------------------------------------------------------------------------
//
// This example code demonstrates some of the basic animation techniques we dicussed
// in class for animating sprite motion, using simple translation and speed control
//
// In this file the following controls are used to demonstrate this:
//
//    1) Use mouse pointer to drag the sprite around
//    2) Arrow keys animate sprite in horizontal or vertical direction
//    3) Increase/Decrease speed of animation using "." or "," key
//    4) Use ctrl-Arrow Keys to apply warp or sin wave to motion to
//       speed up / slow down
//
// In your application, I recommend you encapsulate your sprite in a spite object
// such as this one.
//

//
// Basic Sprite Object
//
Sprite::Sprite() {
    trans.x = 0;
    trans.y = 0;
    scale.x = 1.0;
    scale.y = 1.0;
    rot = 0;
    speed = 0;
    bSelected = false;
}


void Sprite::draw() {
    
    ofSetColor(255, 255, 255, 255);
    
    // draw image centered and add in translation amount
    //
    image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    background.load("images/background.png");
    sprite.image.load("images/USS_Danger.png");
    enemy.image.load("images/enemy.png");
    bullet.image.load("images/bullet.png");
    explosion.load("sounds/explosion.mp3");
    fire.load("sounds/pew.mp3");
    start_point = ofVec3f(50, 500);
    finish_point = ofVec3f(650, 500);
    sprite.trans.set(start_point);
    sprite.speed = 120;   // in pixels per second (screenspace 1 unit = 1 pixel)
    moveDir = MoveStop;
    enemy.trans.set(200, 200);
    bullet.trans.set(500,500);

}

//--------------------------------------------------------------
void ofApp::update() {
    
    updateSprite();
    //updateSprite(bullet);
}

// given a distance return a modulated value between 1-10 based on
// sin wave shape from 0 to PI
//
float ofApp::modulateAccel(float dist) {
    return sin(dist * PI) * 5.0 + 1.0;
}

void ofApp::updateSprite() {
    
    //
    // calculate distance to travel for this update
    //
    float dist = sprite.speed * 2 / ofGetFrameRate();
    ofVec3f dir;
    ofRectangle r = ofGetWindowRect();
    
    //
    //  if the accelerator modifer key is pressed, accelerate and
    //  deacclerate sprite from starting position to window edge
    //
    if (accel) {
        
        switch (moveDir)
        {
            case MoveUp:
            {
                float totalDist = startAccelPoint.y;
                float frac = sprite.trans.y / totalDist;
                dir = ofVec3f(0, -dist * modulateAccel(frac), 0);
            }
                break;
            case MoveDown:
            {
                float totalDist = r.getMaxY() - startAccelPoint.y;
                float frac = sprite.trans.y / totalDist;
                dir = ofVec3f(0, dist * modulateAccel(frac), 0);
            }
                break;
            case MoveLeft:
            {
                float totalDist = startAccelPoint.x;
                float frac = sprite.trans.x / totalDist;
                dir = ofVec3f(-dist * modulateAccel(frac), 0, 0);
            }
                break;
            case MoveRight:
            {
                float totalDist = r.getMaxX() - startAccelPoint.x;
                float frac = sprite.trans.x / totalDist;
                dir = ofVec3f(dist * modulateAccel(frac), 0, 0);
                break;
            }
        }
        
    }
    else
    {
        switch (moveDir)
        {
            case MoveUp:
                dir = ofVec3f(0, -dist, 0);
                break;
            case MoveDown:
                dir = ofVec3f(0, dist, 0);
            case MoveLeft:
                dir = ofVec3f(-dist, 0, 0);
                break;
            case MoveRight:
                dir = ofVec3f(dist, 0, 0);
                break;
        }
    }
    sprite.trans += dir;
}

void ofApp::moveSprite(MoveDir dir) {
    moveDir = dir;
}

void ofApp::stopSprite() {
    moveDir = MoveStop;
}

void ofApp::startAccel() {
    startAccelPoint = sprite.trans;
    accel = true;
}

void ofApp::stopAccel() {
    accel = false;
}


//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    enemy.draw();
    sprite.draw();
    bullet.draw();
}


//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //    cout << "mouse( " << x << "," << y << ")" << endl;
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofPoint mouse_cur = ofPoint(x, y);
    ofVec3f delta = mouse_cur - mouse_last;
    sprite.trans += delta;
    mouse_last = mouse_cur;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouse_last = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

void ofApp::keyPressed(int key) {
    switch (key) {
        case 'C':
        case 'c':
            break;
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            break;
        case 'r':
            break;
        case 's':
            break;
        case 'u':
            break;
        case ' ':
            fire.play();
            bullet.draw();
            bullet.trans.set(400,500);
            break;
        case '.':
            sprite.speed += 30;
            break;
        case ',':
            sprite.speed -= 100;
            break;
        case 'p':
            explosion.play();
            break;
        case OF_KEY_RIGHT:
            stopSprite();
            moveSprite(MoveRight);
            break;
        case OF_KEY_LEFT:
            stopSprite();
            moveSprite(MoveLeft);
            break;
        case OF_KEY_UP:
            
            break;
        case OF_KEY_DOWN:
            
            break;
        case OF_KEY_ALT:
            break;
        case OF_KEY_CONTROL:
            startAccel();
            break;
        case OF_KEY_SHIFT:
            break;
        case OF_KEY_DEL:
            break;
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    switch (key) {
        case ' ':
            break;
        case OF_KEY_LEFT:
        case OF_KEY_RIGHT:
        case OF_KEY_UP:
        case OF_KEY_DOWN:
            stopSprite();
            stopAccel();
            break;
        case OF_KEY_ALT:
            break;
        case OF_KEY_CONTROL:
            stopAccel();
            break;
        case OF_KEY_SHIFT:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


