/*
 * graphics.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */


#include "graphics.h"

#include <iostream>
#include <GL/freeglut.h>

#include "draw_objects.h"

Camera camera_;

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

void display(void)
{
	float lpos[4] = {0., 10., 10., 1.0};  //light's position

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Vector3f cameraPos = camera_.position();
	Vector3f cameraRef = camera_.lookAtReference();
	Vector3f cameraUp = camera_.lookAtUp();

	//std::cout << cameraPos << std::endl;

	gluLookAt(cameraPos.f1(), cameraPos.f2(), cameraPos.f3(), cameraRef.f1(), cameraRef.f2(), cameraRef.f3(), cameraUp.f1(), cameraUp.f2(), cameraUp.f3());  //Camera position and orientation

	glLightfv(GL_LIGHT0,GL_POSITION, lpos);   //Set light position

	glDisable(GL_LIGHTING);			//Disable lighting when drawing floor.
    drawFloor();

	glEnable(GL_LIGHTING);			//Enable lighting when drawing the teapot
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidTeapot(1.0);

    //drawWall(Vector3f(3.0, 1.0, 1.0), Vector3f(1.0, 0.0, 0.0));
    drawMuseumWalls(6, 5.0, 5.0, 1.0, Vector3f(1.0, 0.0, 0.0));

	glFlush();
}

void initGraphics(int argc, char **argv) {
	camera_ = Camera();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Assignment 1 Cameron Stevenson");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_LIGHTING);		//Enable OpenGL states
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 10.0, 1000.0);   //Camera Frustum

	glutDisplayFunc(display);
}

void graphicsMainLoop() {
	glutMainLoop();
}

Camera* camera() {
	return &camera_;
}
