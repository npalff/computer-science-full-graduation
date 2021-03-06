#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <GL/glut.h>

#include <iostream>

using namespace std;

enum CamerasIndex {ORTHOGRAPHIC = 0, PERSPECTIVE = 1};

class Camera
{
	//---------------------------------------------------------------
	//Variables
	//---------------------------------------------------------------	
	protected:
		bool CameraView; //Perspective: true (1), Orthographic: false (0)
		char *CameraName;
		
		//Perspective
		GLdouble PerspAspect;
		GLdouble PerspAngle; //open angle for perspective projection
		GLdouble PerspNear;
		GLdouble PerspFar; 
		
		//Orthographic
		GLdouble OrthoMinX;
		GLdouble OrthoMaxX;
		GLdouble OrthoMinY;
		GLdouble OrthoMaxY;
		GLdouble OrthoNearPlane; 
		GLdouble OrthoFarPlane;
		GLint OrthoInc; //increment for orthographic projection	
				
		//For gluLookAt
		GLdouble EyeX;
		GLdouble EyeY;
		GLdouble EyeZ;
		GLdouble AtX;
		GLdouble AtY;
		GLdouble AtZ;
		GLdouble UpX;
		GLdouble UpY;
		GLdouble UpZ;
	
	//---------------------------------------------------------------
	//Methods
	//---------------------------------------------------------------
	public: 
		//Constructor
		Camera();
		
		//Destructor
		~Camera();
		
		//Setters
		void SetPerspAspect(GLdouble _PerspAspect){ this->PerspAspect = _PerspAspect; }
		void SetPerspAngle(GLdouble _PerspAngle){ this->PerspAngle = _PerspAngle; }
		void SetPerspNear(GLdouble _PerspNear){ this->PerspNear = _PerspNear; }
		void SetPerspFar(GLdouble _PerspFar){ this->PerspFar = _PerspFar; }
		
		void SetOrthoMinX(GLdouble _OrthoMinX){ this->OrthoMinX = _OrthoMinX; }
		void SetOrthoMaxX(GLdouble _OrthoMaxX){ this->OrthoMaxX = _OrthoMaxX; }
		void SetOrthoMinY(GLdouble _OrthoMinY){ this->OrthoMinY = _OrthoMinY; }
		void SetOrthoMaxY(GLdouble _OrthoMaxY){ this->OrthoMaxY = _OrthoMaxY; }
		void SetOrthoNearPlane(GLdouble _OrthoNearPlane){ this->OrthoNearPlane = _OrthoNearPlane; }
		void SetOrthoFarPlane(GLdouble _OrthoFarPlane){ this->OrthoFarPlane = _OrthoFarPlane; }
		void SetOrthoInc(GLint _OrthoInc){ this->OrthoInc = _OrthoInc; } 
				
		void SetEyeX(GLdouble _EyeX){ this->EyeX = _EyeX; }
		void SetEyeY(GLdouble _EyeY){ this->EyeY = _EyeY; }
		void SetEyeZ(GLdouble _EyeZ){ this->EyeZ = _EyeZ; }		
		void SetAtX(GLdouble _AtX){ this->AtX = _AtX; }
		void SetAtY(GLdouble _AtY){ this->AtY = _AtY; }
		void SetAtZ(GLdouble _AtZ){ this->AtZ = _AtZ; }		
		void SetUpX(GLdouble _UpX){ this->UpX = _UpX; }
		void SetUpY(GLdouble _UpY){ this->UpY = _UpY; }
		void SetUpZ(GLdouble _UpZ){ this->UpZ = _UpZ; }			
		
		//Setups the orthographic camera attributes
		void SetOrthoCam(GLdouble, GLdouble, GLdouble, GLdouble,
						 GLdouble, GLdouble, GLint);
						 
		//Setups the perspective camera attributes						 
		void SetPerspCam(GLdouble, GLdouble, GLdouble, GLdouble);	
		
		//Setups the gluLookAt attributes
		void SetCamPosition(GLdouble, GLdouble, GLdouble, GLdouble, 
						    GLdouble, GLdouble, GLdouble, GLdouble,
							GLdouble);				 						 
			
		//Chooses the camera view, between perspective and orthographic	
		void SetCameraView(bool);
		
		//Getters
		GLdouble GetPerspAspect(void){ return this->PerspAspect; }
		GLdouble GetPerspAngle(void){ return this->PerspAngle; }
		GLdouble GetPerspNear(void){ return this->PerspNear; }
		GLdouble GetPerspFar(void){ return this->PerspFar; }
		
		GLdouble GetOrthoMinX(void){ return this->OrthoMinX; }
		GLdouble GetOrthoMaxX(void){ return this->OrthoMaxX; }
		GLdouble GetOrthoMinY(void){ return this->OrthoMinY; }
		GLdouble GetOrthoMaxY(void){ return this->OrthoMaxY; }
		GLdouble GetOrthoNearPlane(void){ return this->OrthoNearPlane; }
		GLdouble GetOrthoFarPlane(void){ return this->OrthoFarPlane; }
		GLdouble GetOrthoInc(void){ return this->OrthoInc; } 
				
		GLdouble GetEyeX(void){ return this->EyeX; }
		GLdouble GetEyeY(void){ return this->EyeY; }
		GLdouble GetEyeZ(void){ return this->EyeZ; }		
		GLdouble GetAtX(void){ return this->AtX; }
		GLdouble GetAtY(void){ return this->AtY; }
		GLdouble GetAtZ(void){ return this->AtZ; }		
		GLdouble GetUpX(void){ return this->UpX; }
		GLdouble GetUpY(void){ return this->UpY; }
		GLdouble GetUpZ(void){ return this->UpZ; }	
		
		bool GetCameraView(void){ return this->CameraView; }
		char * GetCameraName(void){ return this->CameraName; }
		
		//Initializes the camera
		void InitCamera();
		
		


};

#endif
