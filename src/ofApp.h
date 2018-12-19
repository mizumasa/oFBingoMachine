#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAVString.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    vector<int> v_Checked;
    vector<int> v_Remained;
    vector<ofImage> v_KanaImg;
    bool b_Taking;
    int i_Count;
    int i_ShowId;
    int i_LoopCount;
    
    bool b_ImageMode;
    int i_ImageId;
    vector<string> v_ImageFile;
    vector<ofImage> v_Image;
    
    ofxAVString avs;
    ofTrueTypeFont font;
    
    
    ofxIntSlider p_;
    ofxIntSlider p_1;
    ofxToggle filled;
    ofxButton twoCircles;
    ofxButton ringButton;
    ofxPanel gui;

};
