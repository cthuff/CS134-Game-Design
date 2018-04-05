#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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

		
		ofxVec3Slider cameraTarget;
		ofxVec3Slider cameraLookAt;
		ofxVec3Slider cameraPosition;
		ofxFloatSlider reserved;
		ofxPanel gui;
		
		ofPoint conePosition, boxPosition;
		ofConePrimitive cone;
		ofBoxPrimitive box;
	
		ofEasyCam cam;
		
};
