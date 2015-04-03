#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i=0; i<eventNum; i++){
        timerEvent.push_back(false);
    }
    
    float startTime = ofGetElapsedTimeMillis();
    myTimer.push_back(3000);    //最初のイベントはスタート3秒後
    myTimer.push_back(5000);              //２個目のイベントは5秒後
    myTimer.push_back(7000);
    myTimer.push_back(10000);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float timer = ofGetElapsedTimeMillis();
    
    for(int i=0; i<eventNum; i++){
        float time0 = myTimer[i];
        bool bool0 = timerEvent[i];
        
        if(timer >= time0 && !bool0){
            timerEvent[i] = true;
            ofMessage msg(ofToString(i)); //番号だけをメッセージとして飛ばす
            ofSendMessage(msg);
        }
    }
    
}

void ofApp::drawTimerEvent(int num){
    switch(num){
        case 0:
            ofBackground(255,0,0);
            break;
        case 1:
            ofBackground(0,255,0);
            break;
        case 2:
            ofBackground(0,0,255);
            break;
        case 3:
            ofBackground(0);
            break;
        default:
            break;
    }
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    cout << msg.message << endl;
    
    int num = ofToInt(msg.message);
    drawTimerEvent(num);
    
    if(num == eventNum-1){
        cout << "reset" << endl;
        ofResetElapsedTimeCounter();
        for(int i=0; i<eventNum; i++){
            timerEvent[i] = false;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
