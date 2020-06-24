//
//  imageProc.h
//
//  Created by Michael Grierson on 13/11/2017.
//    Updated by Michael Zbyszynski on 13/11/2019.
//

#ifndef imageProc_hpp
#define imageProc_hpp

#include <stdio.h>
#include "ofMain.h"

class imageProc {
    
public:
    
    ofPixels threshRBG(ofPixels pixIn, ofPixels pixOut, int thresh);
    
    ofPixels iThreshRBG(ofPixels pixIn, ofPixels pixOut, int thresh);
    
    ofPixels threshGreyscale(ofPixels pixIn, ofPixels pixOut, int thresh);
    
    ofPixels iThreshGreyscale(ofPixels pixIn, ofPixels pixOut, int thresh);
    
    ofPixels greyscale(ofPixels pixIn, ofPixels pixOut);
    
    ofPixels motionBlur(ofPixels pixIn, ofPixels pixOut, float blur);
    
    ofPixels simpleHighPass(ofPixels pixIn, ofPixels pixOut, float blur);
    
    ofPixels simpleEdgeDetect(ofPixels pixIn, ofPixels pixOut, float edge);
    
    ofPixels resizeX(ofPixels pixIn, ofPixels pixOut, float resize);
    
    ofPixels resizeY(ofPixels pixIn, ofPixels pixOut, float resize);
    
    ofPixels resize(ofPixels pixIn, ofPixels pixOut, float resize);
    
    ofPixels resizeXY(ofPixels pixIn, ofPixels pixOut, float resizeX, float resizeY);
    
    ofPixels resizeXY(ofPixels pixIn, ofPixels pixOut, float resizeX, float resizeY, float anchorX, float anchorY);
    
    ofPixels rotate(ofPixels pixIn, ofPixels pixOut, float theta);
    
    ofPixels rotate(ofPixels pixIn, ofPixels pixOut, float theta, int anchorX, int anchorY, int offsetX, int offsetY, float zoomX, float zoomY);
    
    ofPixels convolve(ofPixels pixIn, ofPixels pixOut, float kernel[9]);
    
    //my filters 
    ofPixels invert(ofPixels pixIn, ofPixels pixOut);
    
    ofPixels myFilter(ofPixels pixIn, ofPixels pixOut);
    
    ofPixels brightness(ofPixels pixIn, ofPixels pixOut, float value);

    
    float lastVal;
    
    float lastVals[9];
    
    float kernel[9];
    
};




#endif /* imageProc_hpp */

