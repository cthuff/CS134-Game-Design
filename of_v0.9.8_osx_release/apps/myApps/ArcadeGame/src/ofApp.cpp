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

//--------------------------------------------------------------
void ofApp::setup(){

	emitter = new Emitter(new EnemySystem());
	emitter->setChildSize(10, 10);
	collider.trans.set(800, 800);
	collider.width = 20;
	collider.height = 20;


    ofSetVerticalSync(true);
    background.load("images/background.png");
    sprite.image.load("images/USS_Danger.png");
    enemy.image.load("images/enemy.png");
    bullet.image.load("images/bullet.png");
    explosion.load("sounds/explosion.mp3");
    sprite.start_point = ofVec3f(70, ofGetWindowHeight() - 90);
    sprite.finish_point = ofVec3f(650, 600);
    sprite.trans.set(sprite.start_point);
    sprite.speed = 120;   // in pixels per second (screenspace 1 unit = 1 pixel)
    enemy.trans.set(200, 200);
    bullet.trans.set(500,500);
    bullets = new vector<Bullet*>();

	gui.setup();
	gui.add(rate.setup("rate", 1, 1, 10));
	gui.add(life.setup("life", 2, .1, 10));
	gui.add(velocity.setup("velocity", ofVec3f(100, 100, 0), ofVec3f(-1000, -1000, -1000), ofVec3f(1000, 1000, 1000)));

	emitter->trans = (ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
	emitter->start();
}

//--------------------------------------------------------------
void ofApp::update() {
    sprite.updateSprite();
}

// given a distance return a modulated value between 1-10 based on
// sin wave shape from 0 to PI
//


void ofApp::updateBullet(Bullet b) {
    float dist = b.speed * 5 / ofGetFrameRate();
    ofVec3f dir;
    ofRectangle r = ofGetWindowRect();
    
    dir = ofVec3f(0, -dist, 0);
    b.trans += dir;
}

//void ofApp::moveBullet(MoveDir dir) {
//    sprite.moveDir = dir;
//}


//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    enemy.draw();
    sprite.draw();
	emitter->draw();
    
	for (int i = 0; i < bullets->size(); i++) {
		Bullet* b = bullets->at(i);
		b->trans.y -= 5;
		if (b->trans.y < 0) {
			b->image.clear();
			bullets->erase(bullets->begin() + i);
		}
		else 
			b->draw();
    }
	//cout << bullets->size() << endl;
}


//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //    cout << "mouse( " << x << "," << y << ")" << endl;
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofPoint mouse_cur = ofPoint(x, 0);
    ofVec3f delta = mouse_cur - mouse_last;
    sprite.trans += delta/2;
    sprite.trans.y = ofGetWindowHeight() - 90;
    sprite.start_point += delta/2;
    sprite.start_point.y= ofGetWindowHeight() - 90 ;
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
            sprite.fire(sprite.trans.x, sprite.trans.y, bullets);
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
			sprite.stopSprite();
			sprite.moveSprite(MoveRight);
            break;
        case OF_KEY_LEFT:
			sprite.stopSprite();
            sprite.moveSprite(MoveLeft);
            break;
        case OF_KEY_UP:
            
            break;
        case OF_KEY_DOWN:
            
            break;
        case OF_KEY_ALT:
            break;
        case OF_KEY_CONTROL:
            
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
            sprite.stopSprite();
            break;
        case OF_KEY_ALT:
            break;
        case OF_KEY_CONTROL:
            
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


