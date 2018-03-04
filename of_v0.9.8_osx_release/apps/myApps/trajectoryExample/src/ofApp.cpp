//  CS 134 - In-Class exercise - Getting started with Particle Physics
//
//  Craig Huff - CS 134 - SJSU CS

#include "ofApp.h"


Particle::Particle() {

	// initialize particle with some reasonable values first;
	//
	velocity.set(0, 0, 0);
	acceleration.set(0, 0, 0);
	position.set(0, 0, 0);
	lifespan = 5;
	birthtime = 0;
	radius = .5;
	damping = .99;
	mass = 1;
    //dt = (1/60);
}

void Particle::draw() {

	ofSetColor(ofColor::blue);
	ofDrawSphere(position, radius);
}

// write your own integrator here.. (hint: it's only 3 lines of code)
//
void Particle::integrate() { 
	// (1) update position from velocity and time interval
    position = position + velocity * 1/60.f;
	// (2) update acceleration from velocity and time interval
    velocity = velocity + acceleration * 1/60.f;
	// (3) multiply final result by damping factor to sim drag
    velocity = velocity * damping;
    //
} 

void ofApp::launchParticle() {

	// Create initialize a new particle with values from sliders
	//
    float time = ofGetElapsedTimeMillis();
	Particle* particle = new Particle();
    particle->birthtime = time;
    particle->lifespan = life;
	particle->velocity.set(velocity);
	particle->acceleration.set(0, -gravity, 0);
	particle->damping = damping;
	particle->radius = radius;

	cout << "vel: " << particle->velocity << endl;
	cout << "accel: " << particle->acceleration << endl;
	cout << "damp: " << damping << endl;
	cout << "rad: " << radius << endl;

	// save your particle here (suggestion: put it into a vector array)
	//
    particles.push_back(particle);

}

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(10);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	framerate = ofGetFrameRate();
    
	// some simple sliders to play with parameters
	//
	gui.setup();
	gui.add(velocity.setup("Initial Velocity", ofVec3f(0, 20, 0), ofVec3f(0, 0, 0), ofVec3f(100, 100, 100)));	
	gui.add(damping.setup("Damping", .99, .1, 1.0));
    gui.add(gravity.setup("Gravity", 10, 1, 20));
	gui.add(radius.setup("Radius", .5, .1, 1.0));
    gui.add(life.setup("Lifespan", 5, .1, 10));
	bHide = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	//
	// need to call integrate() method in your particles here
	//
    for (int i = 0; i < particles.size(); i++){
        Particle* p = particles.at(i);
        p->integrate();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);

	// draw the GUI
	if (!bHide) gui.draw();

	cam.begin();

	// draw a grid
	//
	ofPushMatrix();
	ofRotate(90, 0, 0, 1);
	ofSetLineWidth(1);
	ofSetColor(ofColor::dimGrey);
	ofDrawGridPlane();
	ofPopMatrix();

	// draw particle(s) here..
    for (int i = 0; i < particles.size(); i++){
        Particle* p = particles.at(i);
        if(ofGetElapsedTimeMillis() - p->birthtime > (p->lifespan * 1000))
        {
            particles.erase(particles.begin() + i);
            break;
        }
        p->draw();
    }
	
	cam.end();

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'C':
	case 'c':
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
		break;
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case ' ':
		launchParticle();
		break;
    case 'K':
        particles.clear();
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
