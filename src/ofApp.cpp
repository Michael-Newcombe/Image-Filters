#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //loading my image which is located in the data folder.
    image.load("home-real-estate-106399.jpg");
    //https://www.pexels.com/photo/home-real-estate-106399/
    //initalzing the unprocessed image variable to true so that the orginal image is displayed when the program starts.
    originalImg = true;
    //initalizing the filter variables and setting them all to false so that no filter is being applied to the image when the program starts.
    greyscaleOn = false;
    invertOn = false;
    brightnessOn = false;
    myFilterOn = false;
    edgeDetectOn = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //accessing the pixel information from my image
    pixelsIn = image.getPixels();
    //allocating space for my pixelsOut data, this object is being used to display the processed image and i am setting the width and height of the pixel array to the width and height of the unprocessed image therefore the filtered image will be the same size as the original image.
    pixelsOut.allocate(image.getWidth(), image.getHeight(), OF_IMAGE_COLOR);
    //using the openFrameworks normalize function to map the mouse x postion to be between 0 and 1.
    float normalizedMouseX = ofNormalize(float(mouseX)/ofGetWidth(), 0, 1);
    //if the greyScaleOn variable is true then the greyscale filter is applied to the image
    if (greyscaleOn == true) {
        //applying the greyscale filter from the imageProc class to my image by assigning the output pixels object to the imageProc greyscale function by passing in the input pixels (my original image) and the output pixels.
        pixelsOut = imgProc.greyscale(pixelsIn, pixelsOut);
    }
    //if the invertOn variable is true then the invert filter is applied to the image
    else if (invertOn == true){
        //applying my own filter which i added to the imageProc class called invert, this filter replaces all the colours of the original image with thier exact opposite color. To apply this filter I am using the same method as above.
        pixelsOut = imgProc.invert(pixelsIn, pixelsOut);
    }
    //if the myFilterOn variable is true then the myFilter filter is applied to the image
    else if (myFilterOn == true){
          //applying my own filter which i added to the imageProc class called myFilter, this filter creates an interesting green effect as it maniulates the rgb channels by making the red channel equal the green channel and the green channel equal the red channel, plus an invert effect on both the green and blue channels. To apply this filter I am using the same method as above.
        pixelsOut = imgProc.myFilter(pixelsIn, pixelsOut);
    }
    //if the brightnessOn variable is true then the brightness filter is applied to the image
    else if (brightnessOn == true){
        //applying my own filter which i added to the imageProc class called brightness, this filters decreases the brightess of the image by reducing the rgb channel values, where 0 equals no brightness (each rgb channel is set to 0) and 1 is maximum brightness (original image brightness). To apply this filter I am using the same method as above however I have a third argument which the mouseX position which is used to control the brighness value.
        pixelsOut = imgProc.brightness(pixelsIn, pixelsOut,normalizedMouseX);
    }
    //if the edgeDetectOn variable is true then the edge dectection filter is applied to the image
    else if (edgeDetectOn == true){
         //applying the simpleEdgeDectect filter from the imageProc class to my image by assigning the output pixels object to the imageProc simpleEdgeDectect function using the same method mentioned previously, this filter also uses the mouseX position which is used to control the amount of edge dectection filtering, where 0 is no edge dection and 1 is maximum edge detection.
        pixelsOut = imgProc.simpleEdgeDetect(pixelsIn, pixelsOut,normalizedMouseX);
    }
    //allocating the texture object the processed image which means this object now contains our filtered image
    texture.allocate(pixelsOut);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundColor(32, 32, 32);
    
    //ternary operator, if the orginalImg variable is true then the unfiltered image will be drawn else the filted image will be drawn to the screen.
    originalImg == true ? image.draw(0,0) : texture.draw(0,0);
    
    //UI text
    ofDrawBitmapString("IMAGE FILTERS", ofGetWidth()/1.5, 50);
    ofDrawBitmapString("PRESS 1 FOR GREYSCALE FILTER", ofGetWidth()/1.5, 75);
    ofDrawBitmapString("PRESS 2 FOR INVERT FILTER", ofGetWidth()/1.5, 100);
    ofDrawBitmapString("PRESS 3 FOR MY FILTER", ofGetWidth()/1.5, 125);
    ofDrawBitmapString("PRESS 4 FOR BRIGHTNESS FILTER, \nUSE THE MOUSE X POSITION TO CONTROL \nTHE AMOUNT OF FILTERING", ofGetWidth()/1.5, 150);
     ofDrawBitmapString("PRESS 5 FOR EDGE DETECTION FILTER, \nUSE THE MOUSE X POSITION TO CONTROL \nTHE AMOUNT OF FILTERING", ofGetWidth()/1.5, 200);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //swtich statement which controlls the toggling between filters based on what key has been pressed
    switch (key) {
            //original image
            //if key 0 has been pressed originalImg equals true and everything else equals false
        case '0':
            originalImg = true;
            greyscaleOn = invertOn = myFilterOn = brightnessOn = edgeDetectOn = false;
            break;
            //grayscale filter
            //if key 1 has been pressed greyscaleOn equals true and everything else equals false
        case '1':
            greyscaleOn = true;
            originalImg = invertOn = myFilterOn = brightnessOn = edgeDetectOn = false;
            break;
            //invert filter
            //if key 2 has been pressed invertOn equals true and everything else equals false
        case '2':
            invertOn = true;
            originalImg = greyscaleOn = myFilterOn = brightnessOn = edgeDetectOn = false;
            break;
            //myFilter filter
            //if key 3 has been pressed myFilterOn equals true and everything else equals false
        case '3':
            myFilterOn = true;
            originalImg = greyscaleOn = invertOn = brightnessOn = edgeDetectOn = false;
            break;
            //brightness filter
            //if key 4 has been pressed brightnessOn equals true and everything else equals false
        case '4':
            brightnessOn = true;
            originalImg = greyscaleOn = invertOn = myFilterOn = edgeDetectOn = false;
            break;
        case '5':
            //edge detection filter
            //if key 5 has been pressed edgeDetectOn equals true and everything else equals false
            edgeDetectOn = true;
            originalImg = greyscaleOn = invertOn = brightnessOn = myFilterOn = false;
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
