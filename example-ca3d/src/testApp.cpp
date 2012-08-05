#include "testApp.h"

//--------------------------------------------------------------
testApp::testApp(){
	
}

//--------------------------------------------------------------
void testApp::setup(){

	// numcells match 2d width*height
	ca3d.setup(256,150,16);
	ca3d.countSelf = false;
	ca3d.setRule(69147582);
		
	ofSetBackgroundAuto(false);
	ofBackground(255);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
	
	ca3d.update();
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	
	// here see 16 z layers as 4x4 grid
	
	vector<int> * cells = ca3d.get();
	
	for(int j=0; j<ofGetHeight()-1; j++){
		for(int i=0; i<ofGetWidth()-1; i++){
		
			int val = (cells->at(j*ca3d.dim.x + i));
			if(val > 0)
				ofSetColor(255);
			else
				ofSetColor(0);

			ofRect(i, j, 1, 1);
		}
	}
	
	
	ofSetColor(127);
	ofDrawBitmapString("rule:"+ofToString(ca3d.getRule()), 10,20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	ca3d.setRules();
	
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

