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
}

//--------------------------------------------------------------
void ofApp::update(){

	// udpate your objects here

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
	
		break;
	case OF_KEY_DOWN:
	
		break;
	case OF_KEY_LEFT:
		
		break;
	case OF_KEY_RIGHT:
		
		break;
	case 'h':
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
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
