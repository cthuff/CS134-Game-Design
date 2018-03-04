#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Rocket Surgery!");
    ofSetVerticalSync(true);
//    ofSetFullscreen(true);
    
    background.load("images/background.png");
    sprite.image.load("images/USS_Danger.png");
    bullet.image.load("images/bullet.png");
    explosion.load("sounds/explosion.mp3");
    music.load("sounds/DangerZone.mp3");
    music.setLoop(true);
    music.play();
    
    sprite.start_point = ofVec3f(70, ofGetWindowHeight() - 90);
    sprite.finish_point = ofVec3f(650, 600);
    sprite.trans.set(sprite.start_point);
    sprite.speed = 120;   // in pixels per second (screenspace 1 unit = 1 pixel)
    
    bullet.trans.set(500,500);
    bullets = new vector<Bullet*>();

    // The gui isn't being drawn, but I use it for testing purposes.
	gui.setup();
	gui.add(rate.setup("rate", 1, 1, 10));
	gui.add(life.setup("life", 6.75, .1, 10));
	gui.add(velocity.setup("velocity", ofVec3f(100, 30, 0), ofVec3f(-500, -500, -500), ofVec3f(500, 500, 500)));
    
    emitter = new Emitter(new EnemySystem());
    emitter->trans = (ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
    emitter->start();
    
    
}

//--------------------------------------------------------------
void ofApp::update() {
    sprite.updateSprite();
    emitter->setRate(rate);
    emitter->setLifespan(life * 1000);    // convert to milliseconds
    emitter->setVelocity(velocity);
    emitter->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    sprite.draw();
    
    //checks each bullet for collisions and if it has left the screen (ie. lifespan)
	for (int i = 0; i < bullets->size(); i++) {
		Bullet* b = bullets->at(i);
		b->trans.y -= 5;
		if (b->trans.y < 0) {
			b->image.clear();
			bullets->erase(bullets->begin() + i);
		}
        else {
			b->draw();
            checkCollisions(b);
        }
        
    }
    emitter->draw();
    //gui.draw();
}

/* Each bullet is checking its posistion against the vector of Enemies.
 If the distance of the bullet and any enemy would cause a collision in the nect frame,
 then the ship is "destroyed" and both the ship and vecotr are removed from their respective vectors.
 */
void ofApp::checkCollisions(Bullet* b) {
    float dist = emitter->maxDistPerFrame();
    if(emitter->sys->removeNear(b->trans, emitter->maxDistPerFrame()) )
       {
           for(Bullet* collider: *bullets)
           {
               if (collider == b)
                   b->kill();
           }
       }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofPoint mouse_cur = ofPoint(x, 0);
    ofVec3f delta = mouse_cur - mouse_last;
    sprite.trans += delta;
    sprite.trans.y = ofGetWindowHeight() - 90;
    sprite.start_point += delta;
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
            sprite.stopSprite();
            break;
        case OF_KEY_RIGHT:
            sprite.stopSprite();
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


