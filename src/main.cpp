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

void keyboardLoggingCallback(int key) {
	std::cout << "Key: " + std::to_string(key) << std::endl;
}

void cameraKeyboardCallback(int key) {
	switch(key) {
	case KEY_UP:
		camera()->deltaPosition(Vector3f(0, 0, -1.0));
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
	initGraphics(argc, argv);
	camera()->deltaPosition(Vector3f(0, 0, 12));
	initKeyboard();
	addKeyboardCallback(keyboardLoggingCallback);
	addKeyboardCallback(cameraKeyboardCallback);

	glutTimerFunc(10, updateFunction, 1);
	graphicsMainLoop();
	return 0;
}
