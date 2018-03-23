#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//
	// set up camera stuff
	//
	cam.setDistance(10);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetBackgroundColor(ofColor::black);
    
    
	// setup your objects here
    Particle* particle = new Particle();
    emitter.setEmitterType(EmitterType::DirectionalEmitter);
    emitter.sys->add(*particle);
    emitter.sys->addForce(new ThrustForce(ofVec3f(0,0,0)));
    emitter.start();
}

//--------------------------------------------------------------
void ofApp::update(){

	// udpate your objects here
    emitter.update();
//    for (auto &&p: emitter.sys->particles) {
//        p.integrate();
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();

		// draw grid
		//
		ofPushMatrix();
		ofRotate(90, 0, 0, 1);
		ofSetLineWidth(1);
		ofSetColor(ofColor::dimGrey);
		ofDrawGridPlane();
		ofPopMatrix();

		// draw your objects here
        emitter.draw();
//    cout << emitter.sys->particles.size() << endl;
      for (auto &&p: emitter.sys->particles) {
            p.draw();
        }
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case OF_KEY_UP:
        
        emitter.sys->addForce(new ThrustForce(ofVec3f(0,.03,.01)));
		break;
	case OF_KEY_DOWN:
        
        emitter.sys->addForce(new ThrustForce(ofVec3f(0,-.03,-.01)));
		break;
	case OF_KEY_LEFT:
        
		emitter.sys->addForce(new ThrustForce(ofVec3f(-.03,0,-.01)));
		break;
	case OF_KEY_RIGHT:
        
		emitter.sys->addForce(new ThrustForce(ofVec3f(.03,0,.01)));
		break;
	case 'h':
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case OF_KEY_UP:
//            emitter.stop();
            break;
        case OF_KEY_DOWN:
//            emitter.stop();
            break;
        case OF_KEY_LEFT:
//            emitter.stop();
            break;
        case OF_KEY_RIGHT:
//            emitter.stop();
            break;
        case 'h':
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::playSound() {
	if (soundFileLoaded) soundPlayer.play();
}
