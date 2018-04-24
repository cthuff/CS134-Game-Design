// Craig huff
// CS 134 - terrainDemo
// Octree.h
//

#pragma once
#include "ofMain.h"
#include "ray.h"
#include "box.h"

class Node {

public:
	bool shouldDraw = false;
	bool last = false;

	Box* box = nullptr;

	ofMesh* mesh = nullptr;
	vector<int> verts;

	Node* children[8] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
	int depth = 0;

	Node(Box* newBox, int newDepth, ofMesh* newMesh, bool checkAll, vector<int> possibleVerts) {
		box = newBox;
		mesh = newMesh;
		depth = newDepth;

		if (possibleVerts.size() == 0) {
			cout << "Using all verts as options" << endl;
		}

		verts = Box::vertsInside(box, mesh, possibleVerts);

		//if (verts.size() == 1) cout << "HIT SINGLE VERTEX" << endl;

		if (verts.size() > 1 && depth > 0) {
			// Subdivide box into children
			vector<Box*> childBoxes;
			Box::subDivideBox8(box, childBoxes);

			for (int i = 0; i < 8; i++) {
				children[i] = new Node(childBoxes.at(i), depth - 1, mesh, false, verts);
			}
		}
		else if (verts.size() == 1 || depth == 0) {
			last = true;
		}
	}

	void checkIntersection(Ray ray) {
		if (this->box->intersect(ray, -100, 100)) {
			shouldDraw = true;
			if (!isLeaf()) {
				for (Node* c : children) {
					c->checkIntersection(ray);
				}
			}
		}
	}

	bool isLeaf() {
		return children[0] == nullptr;
	}

	void draw() {
		if (!shouldDraw) return;

		drawBox();

		if (!isLeaf()) {
			for (Node* child : children) {
				child->draw();
			}
		}
	}

	void undraw() {
		if (shouldDraw) {
			shouldDraw = false;
			last = false;
			if (!isLeaf()) {
				for (Node* child : children) {
					child->undraw();
				}
			}
		}
	}


	void drawBox() {
		if (box) {
			
			Vector3 min = box->parameters[0];
			Vector3 max = box->parameters[1];
			
			Vector3 size = max - min;
			Vector3 center = size / 2 + min;
			ofVec3f p = ofVec3f(center.x(), center.y(), center.z());
			float w = size.x();
			float h = size.y();
			float d = size.z();
			ofSetColor(Node::getColor(depth));
			ofDrawBox(p, w, h, d);

			if (last) {
				ofSetColor(ofColor::blue);
				ofDrawSphere(center.x(), center.y(), center.z(), 0.5);
			}
		}
		else {
			cout << "Box was missing!" << endl;
		}
	}

	static ofColor getColor(int d) {
		if (d == 0) return ofColor::azure;
		if (d == 1) return ofColor::salmon;
		if (d == 2) return ofColor::peachPuff;
		if (d == 3) return ofColor::fuchsia;
		if (d == 4) return ofColor::mediumSeaGreen;
		if (d == 5) return ofColor::blueSteel;
		if (d == 6) return ofColor::saddleBrown;
		if (d == 7) return ofColor::sienna;
		if (d == 8) return ofColor::red;
		if (d == 9) return ofColor::navajoWhite;
		else return ofColor::pink;
	}
};

class Octree {

	Node* head;

	Octree(int depth) {

	}
};
