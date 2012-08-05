#include "testApp.h"

//--------------------------------------------------------------
testApp::testApp(){
	
}

//--------------------------------------------------------------
void testApp::setup(){
	
	ca2d.setup( ofGetWidth(), ofGetHeight() );	
	ca2d.setRule(1109);
	ca2d.countSelf = false;
	
	ofSetBackgroundAuto(false);
	ofBackground(255);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
	
	ca2d.update();
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	vector<int> * cells = ca2d.get();
	
	for(int j=0; j<ofGetHeight()-1; j++){
		for(int i=0; i<ofGetWidth()-1; i++){		
			int val = cells->at(j*ca2d.dim.x + i);
			if(val > 0)
				ofSetColor(255);
			else
				ofSetColor(0);

			ofRect(i, j, 1, 1);
		}
	}
		
	
	ofSetColor(127);
	ofDrawBitmapString("rule:"+ofToString(ca2d.getRule()), 10,20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	ca2d.setRules();	
	
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

