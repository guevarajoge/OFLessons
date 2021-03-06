#include "ofApp.h"

float lastRender;




//--------------------------------------------------------------
void ofApp::setup(){
    
    
    for (int x=0; x < 25; ++x) {
        for (int y=0; y < 14; ++y) {
            eyeBox eye;
            eye.setup(ofVec2f(10 + x * 90,10 + y * 90),ofRandom(10,50));
            eyes.push_back(eye);
        }
    }
    
    
    ofSetCircleResolution(6);
    ofEnableAntiAliasing();

    ofHideCursor();
	ofSetFrameRate(60);

}

//--------------------------------------------------------------
void ofApp::update(){
    for (eyeBox& eye : eyes) {
        eye.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	// uncomment this to see how a shape is composed
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // use the & sign to create a reference instead of a copy.
    for (eyeBox& eye : eyes) {
        eye.draw();
    }
    
    
	// adjust mouse cursor
    ofPushMatrix();
        ofTranslate(ofGetMouseX(), ofGetMouseY());
        ofRotate(ofGetElapsedTimeMillis()/4);
        ofSetColor(255,255,255);
        ofDrawCircle(0, 0, 10);
    ofPopMatrix();


	ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        ofToggleFullscreen();
    }
}

