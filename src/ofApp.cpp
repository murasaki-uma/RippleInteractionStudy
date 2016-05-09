#include "ofApp.h"
#include "ripple.h"

RippleAnimation rippleAnimation;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	rippleAnimation.setup(10);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	rippleAnimation.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateX(70);
	rippleAnimation.draw();
	ofPopMatrix();


	
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

	rippleAnimation.count();

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
