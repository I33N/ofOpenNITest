#include "cinder/gl/gl.h"

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	openNI.setup();

	camera = ci::CameraPinhole(800,600,600.0f,600.0f,400.0f,300.0f);
	//cam.setCurrentCam( camera );
	arcball.setWindowSize(ci::Vec2i(ofGetWidth(),ofGetHeight()));
	arcball.setCenter(ci::Vec2i(ofGetWidth()/2,ofGetHeight()/2));
	arcball.setRadius(150);
}

//--------------------------------------------------------------
void testApp::update(){

	openNI.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	ci::gl::clear();

	//ci::gl::setMatrices(camera);
	//ci::gl::setMatrices( cam.getCamera() );
	
	ci::gl::rotate( arcball.getQuat() );
	ci::gl::rotate(ci::Vec3f(0.0f,180.0f,180.0f));
	ci::gl::translate(ci::Vec3f(ofGetWidth()/2,-ofGetHeight()/2,0.0f));
	

	openNI.drawShape();

	ci::gl::drawCoordinateFrame(800.0f,10.0f,5.0f);

        XnUserID aUsers[15]; 
        XnUInt16 nUsers = 15; 
        openNI.getUserGenerator()->GetUsers(aUsers, nUsers); 
        
        for (int i = 0; i < nUsers; ++i) 
        { 
                XnPoint3D com; 
                openNI.getUserGenerator()->GetCoM(aUsers[i], com); 
               	//g_DepthGenerator.ConvertRealWorldToProjective(1, &com, &com); 
        
		ci::gl::pushMatrices();
                	ci::gl::translate(ci::Vec3f(com.X,com.Y,com.Z));
			ci::gl::drawCoordinateFrame(800.0f,10.0f,5.0f);
			ci::gl::drawColorCube( ci::Vec3f::zero(), ci::Vec3f( 100.0f, 100.0f, 100.0f ) );
                ci::gl::popMatrices();

        }
	
	//openNI.drawTexture();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
        ci::Vec2i P(x,y);
        P.y = ofGetHeight() - P.y;
        arcball.mouseDrag( P );
        //cam.mouseDrag( P, button==0, button==1, button==2 );
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
        ci::Vec2i P(x,y);
        P.y = ofGetHeight() - P.y;
        arcball.mouseDown( P );
        //cam.mouseDown( P );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

