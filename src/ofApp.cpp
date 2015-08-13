#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < flocks.size(); i++) {
        flocks[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);

    for (int i = 0; i < flocks.size(); i++) {
        flocks[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    flocks.push_back(Flock(ofVec2f(x, y)));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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