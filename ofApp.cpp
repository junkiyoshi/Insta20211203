#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetLineWidth(2);
	ofEnableDepthTest();

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->face.clear();
	this->frame.clear();

	auto len = 600;
	auto depth = len / 25;
	while (true) {

		auto param_start = ofMap(ofNoise(len * 0.002, ofGetFrameNum() * 0.0015), 0, 1, 0, 200);
		for (auto param = param_start; param < param_start + 50; param += 2) {

			this->setBoxToMesh(this->face, this->frame, glm::vec3(this->make_point(len, param), len / 2 + depth), len / 25);
		}

		len -= len / 10;
		if (len < 150) { break; }
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.666666666666);
	ofRotateZ(ofGetFrameNum() * 0.333333333333);

	for (int i = 0; i < 4; i++) {

		ofRotateY(90);

		ofSetColor(255);
		this->face.draw();

		ofSetColor(0);
		this->frame.drawWireframe();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float size) {

	this->setBoxToMesh(face_target, frame_target, location, size, size, size);
}

//--------------------------------------------------------------
void ofApp::setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float height, float width, float depth) {

	int face_index = face_target.getNumVertices();
	int frame_index = frame_target.getNumVertices();

	face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * 0.5 * 0.99, depth * -0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * 0.5 * 0.99, depth * -0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * 0.5 * 0.99, depth * 0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * 0.5 * 0.99, depth * 0.5 * 0.99));

	face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * -0.5 * 0.99, depth * -0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * -0.5 * 0.99, depth * -0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * -0.5 * 0.99, depth * 0.5 * 0.99));
	face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * -0.5 * 0.99, depth * 0.5 * 0.99));

	face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 2);
	face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 3);

	face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 6);
	face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 7);

	face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 1);
	face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 1);

	face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 6);
	face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 1);

	face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 7);
	face_target.addIndex(face_index + 7); face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 2);

	face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 7); face_target.addIndex(face_index + 4);
	face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 3);

	frame_target.addVertex(location + glm::vec3(width * -0.5, height * 0.5, depth * -0.5));
	frame_target.addVertex(location + glm::vec3(width * 0.5, height * 0.5, depth * -0.5));
	frame_target.addVertex(location + glm::vec3(width * 0.5, height * 0.5, depth * 0.5));
	frame_target.addVertex(location + glm::vec3(width * -0.5, height * 0.5, depth * 0.5));

	frame_target.addVertex(location + glm::vec3(width * -0.5, height * -0.5, depth * -0.5));
	frame_target.addVertex(location + glm::vec3(width * 0.5, height * -0.5, depth * -0.5));
	frame_target.addVertex(location + glm::vec3(width * 0.5, height * -0.5, depth * 0.5));
	frame_target.addVertex(location + glm::vec3(width * -0.5, height * -0.5, depth * 0.5));

	frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 1);
	frame_target.addIndex(frame_index + 1); frame_target.addIndex(frame_index + 2);
	frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 3);
	frame_target.addIndex(frame_index + 3); frame_target.addIndex(frame_index + 0);

	frame_target.addIndex(frame_index + 4); frame_target.addIndex(frame_index + 5);
	frame_target.addIndex(frame_index + 5); frame_target.addIndex(frame_index + 6);
	frame_target.addIndex(frame_index + 6); frame_target.addIndex(frame_index + 7);
	frame_target.addIndex(frame_index + 7); frame_target.addIndex(frame_index + 4);

	frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 4);
	frame_target.addIndex(frame_index + 1); frame_target.addIndex(frame_index + 5);
	frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 6);
	frame_target.addIndex(frame_index + 3); frame_target.addIndex(frame_index + 7);
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, float param) {

	glm::vec2 base, next;

	auto param_i =  (int)param % 100;
	auto param_p = param - (int)param;

	if (param_i < 25) {

		base = glm::vec2(ofMap(param_i, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param_i < 50) {

		base = glm::vec2(len * 0.5, ofMap(param_i, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param_i < 75) {

		base = glm::vec2(ofMap(param_i, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		base = glm::vec2(-len * 0.5, ofMap(param_i, 75, 100, len * 0.5, -len * 0.5));
	}

	param_i = (param_i + 1) % 100;
	if (param_i < 25) {

		next = glm::vec2(ofMap(param_i, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param_i < 50) {

		next = glm::vec2(len * 0.5, ofMap(param_i, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param_i < 75) {

		next = glm::vec2(ofMap(param_i, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		next = glm::vec2(-len * 0.5, ofMap(param_i, 75, 100, len * 0.5, -len * 0.5));
	}

	return base + (next - base) * param_p;
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}