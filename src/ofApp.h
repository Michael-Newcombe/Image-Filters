#pragma once

#include "ofMain.h"
#include "imageProc.h"

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
    
        //creating an ofImage obejct so that i can load my image file.
        ofImage image;
        //creating an imageProc object for processing my image.
        imageProc imgProc;
        //creating an ofTexture object so I can draw my processed image to the graphics card.
        ofTexture texture;
        //creating two ofPixels objects so that I can access the rgb pixel array from my image
        //pixel information of the unprocessed image (original image).
        ofPixels pixelsIn;
        //pixel information of the processed image.
        ofPixels pixelsOut;
        //boolean variable for displaying the unprocessed image.
        bool originalImg;
        //boolean variables for toggling which filter should be applied to the image.
        bool greyscaleOn;
        bool invertOn;
        bool brightnessOn;
        bool myFilterOn;
        bool edgeDetectOn;
		
};
