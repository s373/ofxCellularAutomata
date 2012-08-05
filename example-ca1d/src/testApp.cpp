#include "testApp.h"

//--------------------------------------------------------------
testApp::testApp(){

}

//--------------------------------------------------------------
void testApp::setup(){

	ca1d.setup( ofGetWidth() );	
	ca1d.setRules();
	y = 0;
	
	ofSetBackgroundAuto(false);
	ofBackground(255);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
	
	ca1d.update();
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	
	vector<int> * cells = ca1d.get();
	
	for(int i=0; i<ofGetWidth()-1; i++){
		
		int val = (cells->at(i));
		if(val > 0)
			ofSetColor(255);
		else
			ofSetColor(0);

		ofRect(i, y, 1, 1);
	}
	
	y=(y+1)%ofGetHeight();
	
	ofSetColor(127);
	ofDrawBitmapString("rule:"+ofToString(ca1d.getRule()), 10,20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	setup();
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}

