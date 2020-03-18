//  ========================================================================
//  COSC363: Computer Graphics (2020);  University of Canterbury.
//
//  FILE NAME: Teapot.cpp
//  See Lab01.pdf for details
//  ========================================================================

#include <iostream>
#include <string>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/freeglut.h>
#include "keyboard.h"
#include "camera.h"

Camera camera;

//--Draws a grid of lines on the floor plane -------------------------------
void drawFloor()
{
	glColor3f(0., 0.5,  0.);			//Floor colour

	for(int i = -50; i <= 50; i ++)
	{
		glBegin(GL_LINES);			//A set of grid lines on the xz-plane
			glVertex3f(-50, -0.75, i);
			glVertex3f(50, -0.75, i);
			glVertex3f(i, -0.75, -50);
			glVertex3f(i, -0.75, 50);
		glEnd();
	}
}

//--Display: ---------------------------------------------------------------
//--This is the main display module containing function calls for generating
//--the scene.
void display(void) 
{ 
	float lpos[4] = {0., 10., 10., 1.0};  //light's position

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Vector3f cameraPos = camera.position();
	Vector3f cameraRef = camera.lookAtReference();
	Vector3f cameraUp = camera.lookAtUp();

	std::cout << cameraPos << std::endl;
	std::cout << cameraRef << std::endl;
	std::cout << cameraUp << std::endl;
	std::cout << std::endl;

	gluLookAt(cameraPos.f1(), cameraPos.f2(), cameraPos.f3(), cameraRef.f1(), cameraRef.f2(), cameraRef.f3(), cameraUp.f1(), cameraUp.f2(), cameraUp.f3());  //Camera position and orientation

	glLightfv(GL_LIGHT0,GL_POSITION, lpos);   //Set light position

	glDisable(GL_LIGHTING);			//Disable lighting when drawing floor.
    drawFloor();

	glEnable(GL_LIGHTING);			//Enable lighting when drawing the teapot
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidTeapot(1.0);

	glFlush(); 
} 

//----------------------------------------------------------------------
void initialize(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_LIGHTING);		//Enable OpenGL states
	glEnable(GL_LIGHT0);
 	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 10.0, 1000.0);   //Camera Frustum
}

void exampleKeyboardCallback(int key) {
	std::cout << "Key: " + std::to_string(key) << std::endl;
	Vector3f cameraPos = camera.position();
	switch(key) {
	case KEY_UP:
		std::cout << "UP" << std::endl;
		camera.deltaPosition(Vector3f(0, 0, -1.0));
		std::cout << cameraPos << std::endl;
		break;
	default:
		break;
	}
}

void updateFunction(int te)
{
	glutPostRedisplay();
	glutTimerFunc(10, updateFunction, 1);
}

//  ------- Main: Initialize glut window and register call backs -------
int main(int argc, char **argv) 
{ 
	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);  
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Teapot");
	initKeyboard();
	camera.deltaPosition(Vector3f(0, 0, 12));
	Vector3f cameraPos = camera.position();
	Vector3f cameraRef = camera.lookAtReference();
	Vector3f cameraUp = camera.lookAtUp();

	std::cout << cameraPos << std::endl;
	std::cout << cameraRef << std::endl;
	std::cout << cameraUp << std::endl;
	std::cout << "\n" << std::endl;
	addKeyboardCallback(exampleKeyboardCallback);
	initialize();
	glutDisplayFunc(display);
	glutTimerFunc(10, updateFunction, 1);
	glutMainLoop();
	return 0;
}
