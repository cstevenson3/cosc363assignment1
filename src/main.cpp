/*
 * main.cpp
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

//stdlib
#include <iostream>
#include <string>
#include <cmath>

//gl
#include <GL/freeglut.h>

//ours
#include "keyboard.h"
#include "camera.h"
#include "graphics.h"
#include "our_time.h"

//objects
#include "museum_walls.h"
#include "floor_wireframe.h"
#include "double_pendulum.h"
#include "rubix_cube.h"

DoublePendulum doublePendulum_;

void keyboardLoggingCallback(int key) {
	std::cout << "Key: " + std::to_string(key) << std::endl;
}

long int lastTime;

int updateCounter = 0;

void updateFunction(int te)
{
	long int currentTime = our_time::unixTimeMS();
	int dt = currentTime - lastTime;
	lastTime = currentTime;

	//update objects
	int res = 100;
	for(int i = 0; i < res; i++) {
		doublePendulum_.update((dt/(1000.0 * res)));
	}

	camera()->update();

	glutPostRedisplay();
	glutTimerFunc(10, updateFunction, 1);
}

//  ------- Main: Initialize glut window and register call backs -------
int main(int argc, char **argv) 
{
	initGraphics(argc, argv);
	camera()->setMode(Camera::DOOM);
	camera()->deltaPosition(Vector3f(0, 1.8, 12));
	initKeyboard();
	//addKeyboardCallback(keyboardLoggingCallback);

	FloorWireframe floorWireframe = FloorWireframe();
	scene()->addDrawable(floorWireframe);

	MuseumWalls museumWalls = MuseumWalls();
	scene()->addDrawable(museumWalls);

	//doublePendulum_ = DoublePendulum(Vector3f(0.5,0.5,0.5), Vector3f(0.8, 0.0, 0.0), 9.81, 0.5, 0.6, 0.5, 1., 270, 170);
	//*(doublePendulum_.position()) = Vector3f(0.0, 5.0, 0.0);
	//scene()->addDrawable(doublePendulum_);

	RubixCube cube = RubixCube();
	*(cube.position()) = Vector3f(0.0, 5.0, 0.0);
	scene()->addDrawable(cube);

	lastTime = our_time::unixTimeMS();
	glutTimerFunc(10, updateFunction, 1);
	graphicsMainLoop();
	return 0;
}
