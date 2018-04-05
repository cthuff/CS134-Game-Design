//
//  In-Class Exercise - Cameras and Viewing
//
//  Kevin M. Smith



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

	// setup some shapes
	//
	conePosition.set(3, 0, 3);
	cone.setScale(.98, .98, .98);
	cone.set(1.0, 3.0);
	cone.setPosition(conePosition);

	boxPosition.set(-3, 0, -3);
	box.setScale(.98, .98, .98);
	box.set(3.0);
	box.setPosition(boxPosition);

	// setup a few GUI sliders
	//
	gui.setup();
	gui.add(cameraTarget.setup("CameraTarget", ofVec3f(0, 0, 0), ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10)));	
    
    //connect camera position
    gui.add(cameraLookAt.setup("CameraLookAt", ofVec3f(0, 0, 0), ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10)));
    //connect look at camera
    gui.add(cameraPosition.setup("CameraPosition", ofVec3f(0, 0, 0), ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10)));
    
    //cam.setTarget(boxPosition);
    cam.lookAt(conePosition);
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.setTarget(cameraTarget);
    cam.setPosition(cameraPosition);
    cam.lookAt(cameraLookAt);
}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();

	cam.begin();

		ofSetDepthTest(true);

		// draw grid
		//
		ofPushMatrix();
		ofRotate(90, 0, 0, 1);
		ofSetLineWidth(1);
		ofSetColor(ofColor::dimGrey);
		ofDrawGridPlane();
		ofPopMatrix();

		// draw some shapes
		//
		ofSetColor(ofColor::blue);
		cone.drawFaces();
		ofSetColor(ofColor::black);
		cone.drawWireframe();

		ofSetColor(ofColor::blue);
		box.drawFaces();
		ofSetColor(ofColor::black);
		box.drawWireframe();

		ofSetDepthTest(false);
	

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
