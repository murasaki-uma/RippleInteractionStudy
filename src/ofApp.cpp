#include "ofApp.h"

class Ripple 
{
public:
	Ripple(void) {};
	~Ripple(void) {};

	void setup(int VertexNum, float Radius, float WaveAmp, ofColor lineColor)
	{
		color = lineColor;
		waveAmp = startWaveAmp = WaveAmp;
		radius = startRadius = Radius;
		vertexNum = VertexNum;
		createMesh();
		speed = 1;
	}
	void init() {
		z_r = 0.0;
		speed = 1;
		color.set(255);
		radius = startRadius;
		createMesh();
	}
	void createMesh() {
		circleMesh.clear();
		z_r = 0;
		waveAmp = startWaveAmp;
		for (int i = 0; i < vertexNum; i++)
		{
			float r = TWO_PI / vertexNum * i;
			z_r += 0.4;
			float x = radius * cos(r);
			float y = radius * sin(r);
			float z = waveAmp * sin(z_r);
			circleMesh.addVertex(ofVec3f(x, y, z));
		}
	}

	void draw() {
		circleMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
		ofPushStyle();
		ofSetColor(color);
		if (UPDATE_START) 
		{
			circleMesh.drawWireframe();
		}
		
		ofPopStyle();
	}

	void update() {
		if (UPDATE_START)
		{
			speed *= 1.04;
			radius += speed;
			createMesh();
			waveAmp += 0.2;
			color.a -= 255 * radius / ofGetWidth() / 2 * 0.1;


			if (color.a <= 0.0 || radius > ofGetWidth()/2) {
				init();
				UPDATE_START = false;
			}
		}
		
	}

	void log()
	{
		cout << UPDATE_START << endl;
	}

	void startUpdate() {
		UPDATE_START = true;
	}
private:

	int vertexNum;
	float startRadius;
	float radius;
	ofMesh circleMesh;
	float waveAmp;
	float startWaveAmp;
	float z_r;
	float speed;
	bool UPDATE_START = false;
	ofColor color;
};


class RippleAnimation {
public:
	RippleAnimation(void) {};
	~RippleAnimation(void) {};

	void setup(int CircleNum)
	{
		circleNum = CircleNum;
		for (int i = 0; i < circleNum; i++)
		{
			Ripple r;
			r.setup(150, 0, 1, ofColor(255));
			ripples.push_back(r);
		}
	}

	void update()
	{
		for (int i = 0; i < circleNum; i++)
		{
			ripples[i].update();
		}
	}

	void draw()
	{
		for (int i = 0; i < circleNum; i++)
		{
			ripples[i].draw();
			//cout << i << endl;
			//ripples[i].log();
		}
	}

	void count() {

		if (counter == circleNum-1) 
		{
			counter = 0;
		}
		else 
		{
			counter++;
		}
		if (counter >= 0) 
		{
			ripples[counter].startUpdate();
		}
		

	}

private:
	int counter = -1;
	int circleNum;
	vector<Ripple>ripples;
};

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
