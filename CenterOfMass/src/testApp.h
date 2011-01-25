#ifndef _TEST_APP
#define _TEST_APP

#include "ofxSimpleOpenNI.h"

#include "cinder/gl/gl.h"
//#include "cinder/Arcball.h"
//#include "cinder/MayaCamUI.h"

//#include "CameraPinhole.h"
#include "ofMain.h"

class testApp : public ofBaseApp{

	protected:
		ofxSimpleOpenNI	openNI;
		
		//ci::CameraPinhole 	camera;
		//ci::Arcball		arcball;
		//ci::MayaCamUI		cam;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

};

#endif
