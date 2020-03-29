/*
 * main.cpp
 *
 *  Created on: 17/03/2020
 *      Author: Cameron Stevenson
 */

#include <iostream>
#include <string>
#include <cmath>
#include <GL/freeglut.h>
#include "keyboard.h"
#include "camera.h"
#include "graphics.h"
#include "museum_walls.h"
#include "floor_wireframe.h"

void keyboardLoggingCallback(int key) {
	std::cout << "Key: " + std::to_string(key) << std::endl;
}

void updateFunction(int te)
{

	//update objects

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


	glutTimerFunc(10, updateFunction, 1);
	graphicsMainLoop();
	return 0;
}
