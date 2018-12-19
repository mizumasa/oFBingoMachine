#include "ofApp.h"

#define TOTAL_NUM 46
#define HISTORY_OFFSET_X 50
#define HISTORY_OFFSET_Y 50
#define HISTORY_SIZE 80
#define CENTER_OFFSET_Y 50
#define CENTER_SIZE 300
#define HISTORY_NUM_X 18

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i<TOTAL_NUM;i++){
        ofImage buf;
        buf.load("kana/"+ofToString(i+1)+".png");
        v_KanaImg.push_back(buf);
        v_Remained.push_back(i+1);
    }
    v_ImageFile.push_back("shohin/1.jpg");
    v_ImageFile.push_back("shohin/2.jpg");
    v_ImageFile.push_back("shohin/3.jpg");
    v_ImageFile.push_back("shohin/4.jpg");
    v_ImageFile.push_back("shohin/5.jpg");
    v_ImageFile.push_back("shohin/6.jpg");
    v_ImageFile.push_back("shohin/7.jpg");
    v_ImageFile.push_back("shohin/8.jpg");
    v_ImageFile.push_back("shohin/9.jpg");
    v_ImageFile.push_back("shohin/10.jpg");
    v_ImageFile.push_back("shohin/11.jpg");
    v_ImageFile.push_back("shohin/12.jpg");
    v_ImageFile.push_back("shohin/13.jpg");
    v_ImageFile.push_back("shohin/14.jpg");
    v_ImageFile.push_back("shohin/15.jpg");
    for(int i = 0; i<v_ImageFile.size();i++){
        ofImage buf;
        buf.load(v_ImageFile[i]);
        v_Image.push_back(buf);
    }
    cout<<"load file num "<<v_Image.size()<<endl;
    
    i_ShowId = 0;
    b_ImageMode = false;
    b_Taking = false;
    i_Count = 0;
    i_LoopCount = 0;
    i_ImageId = -1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    i_LoopCount += 1;
    i_LoopCount = i_LoopCount % 100;
    int i_RemainNum = 0;
    i_RemainNum = v_Remained.size();
    if(b_Taking){
        i_Count += 1;
        i_ShowId = int(MIN( ofRandom(0, i_RemainNum) , i_RemainNum - 0.000000001));
        //i_ShowId = int(ofRandom(0,5));
        cout << i_ShowId << endl;
    }
    if(i_Count > 10){
        int i_ChosedId = 0;
        int i_Chosed = 0;
        i_ChosedId = int(MIN( ofRandom(0, i_RemainNum) , i_RemainNum - 0.000000001));
        i_Chosed = v_Remained[i_ChosedId];
        cout << i_Chosed << endl;

        v_Remained.erase(v_Remained.begin() + i_ChosedId);
        v_Checked.push_back(i_Chosed);
        
        i_Count = 0;
        b_Taking = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    if(b_ImageMode){
        if(i_ImageId>=0){
            int imageW,imageH;
            imageW = v_Image[i_ImageId].getWidth();
            imageH = v_Image[i_ImageId].getHeight();
            imageW = ofGetHeight() * imageW / imageH;
            imageH = ofGetHeight();
            v_Image[i_ImageId].draw(ofGetWidth()/2-imageW/2,0,imageW,imageH);
        }
        int pastePosX,pastePosY;
        if(v_Checked.size()>0){
            for(int i = 0;i<v_Checked.size();i++){
                pastePosX = i % HISTORY_NUM_X;
                pastePosY = int(i / HISTORY_NUM_X);
                v_KanaImg[int(v_Checked[i]) - 1].draw(HISTORY_OFFSET_X+HISTORY_SIZE*pastePosX,
                                                 HISTORY_OFFSET_Y+HISTORY_SIZE*pastePosY,
                                                 HISTORY_SIZE,HISTORY_SIZE);
            }
        }
        if(v_Checked.size()>0 and !b_Taking){
            v_KanaImg[int(v_Checked[v_Checked.size()-1])-1].draw(ofGetWidth()/2-CENTER_SIZE/2,CENTER_OFFSET_Y+ofGetHeight()/2-CENTER_SIZE/2,CENTER_SIZE,CENTER_SIZE);
        }
        if(b_Taking){
            v_KanaImg[v_Remained[i_ShowId]-1].draw(ofGetWidth()/2-CENTER_SIZE/3,CENTER_OFFSET_Y+ofGetHeight()/2-CENTER_SIZE/3,CENTER_SIZE*2/3,CENTER_SIZE*2/3);
        }
    }else{
        string buf="Checked:";
        for(int i = 0;i<v_Checked.size();i++){
            buf+= (ofToString(v_Checked[i]) + ":");
        }
        cout << buf << endl;
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
        case OF_KEY_TAB:
            b_ImageMode = !b_ImageMode;
            break;
        case OF_KEY_RETURN:
            if(!b_Taking){
                if(v_Remained.size()>0){
                    b_Taking = true;
                }
            }
            break;
        case OF_KEY_LEFT:
            if(v_Checked.size()>0){
                int i_Back = v_Checked[ v_Checked.size() - 1];
                v_Checked.pop_back();
                v_Remained.push_back(i_Back);
            }
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            i_ImageId = int(key - '1');
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case '0':
            i_ImageId = 9;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case 'q':
            i_ImageId = 10;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case 'w':
            i_ImageId = 11;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case 'e':
            i_ImageId = 12;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case 'r':
            i_ImageId = 13;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
        case 't':
            i_ImageId = 14;
            i_ImageId = MIN( i_ImageId, v_Image.size() - 1);
            cout<< "image id " <<i_ImageId<<endl;
            break;
    }
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
