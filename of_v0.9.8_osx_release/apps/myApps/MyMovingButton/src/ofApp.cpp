#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    button_pos = ofPoint(200,200);
    button_state = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    button.set(button_pos, 300, 200);
    ofDrawRectangle(button);
    if (button_state)
        ofSetColor(255, 0, 0);
    else
        ofSetColor(100,100,100);
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
    if (this->button.inside(x, y)){
    ofPoint mouse_current = ofPoint(x,y);
    ofVec3f delta = mouse_current - button_last;
    button_pos += delta;
    button_last = mouse_current;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    button_last = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofPoint mouse_current = ofPoint(x,y);
    if (this->button.inside(x, y))
        button_state = !button_state;
    
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
