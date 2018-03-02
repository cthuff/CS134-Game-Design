#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
    
//    emitter = new Emitter(new EnemySystem());
//    emitter->setChildSize(10, 10);
//    collider.trans.set(800, 800);
//    collider.width = 20;
//    collider.height = 20;
//    emitter->trans = (ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
//    emitter->start();
//    emitter->setChildImage(bullet.image);
}

//--------------------------------------------------------------
void ofApp::update() {
    sprite.updateSprite();
//    emitter->setRate(rate);
//    emitter->setLifespan(life * 1000);    // convert to milliseconds
//    emitter->setVelocity(velocity);
//    emitter->update();
    
    checkCollisions();
}


void ofApp::updateBullet(Bullet b) {
    float dist = b.speed * 5 / ofGetFrameRate();
    ofVec3f dir;
    ofRectangle r = ofGetWindowRect();
    
    dir = ofVec3f(0, -dist, 0);
    b.trans += dir;
}


//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    enemy.draw();
    sprite.draw();
	
    
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
    emitter->draw();
    collider.draw();
    gui.draw();

}

void ofApp::checkCollisions() {
    
    float dist = emitter->maxDistPerFrame();
    collider.width = dist;
    collider.height = dist;
    emitter->sys->removeNear(collider.trans, emitter->maxDistPerFrame());
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
            if(isUp)
            sprite.fire(sprite.trans.x, sprite.trans.y, bullets);
            isUp = false;
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
			sprite.moveSprite(MoveRight);
            break;
        case OF_KEY_LEFT:
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
            isUp = true;
            break;
        case OF_KEY_LEFT:
            break;
        case OF_KEY_RIGHT:
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


