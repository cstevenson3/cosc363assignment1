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
Scene scene_;

void display(void)
{
	float l0pos[4] = {-3., 5., 0., 1.0};  //light 0's position
	float l1pos[4] = {3., 5., 0., 1.0};  //light 1's position
	float l1diffuse[4] = {1., 1., 1., 1.0};  //light 1's diffuse

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Vector3f cameraPos = camera_.position();
	Vector3f cameraRef = camera_.lookAtReference();
	Vector3f cameraUp = camera_.lookAtUp();
	gluLookAt(cameraPos.f1(), cameraPos.f2(), cameraPos.f3(), cameraRef.f1(), cameraRef.f2(), cameraRef.f3(), cameraUp.f1(), cameraUp.f2(), cameraUp.f3());  //Camera position and orientation

	glLightfv(GL_LIGHT0, GL_POSITION, l0pos);   //Set light 0 position
	glLightfv(GL_LIGHT1, GL_POSITION, l1pos);   //Set light 1 position
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1diffuse);   //Set light 1 diffuse

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

    scene_.draw();

	glFlush();
}

void initGraphics(int argc, char **argv) {
	camera_ = Camera();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("COSC363 Assignment 1 57052612 Cameron Stevenson");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	float black[4] = {0., 0., 0., 1.0};
	float darkgrey[4] = {0.1, 0.1, 0.1, 1.0};
	float lightgrey[4] = {0.15, 0.15, 0.15, 1.0};
	float white[4]  = {1.0, 1.0, 1.0, 1.0};
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, black);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01);
//	glLightfv(GL_LIGHT1, GL_AMBIENT, black);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 1500.0);

	glutDisplayFunc(display);
}

void graphicsMainLoop() {
	glutMainLoop();
}

Camera* camera() {
	return &camera_;
}

Scene* scene() {
	return &scene_;
}
