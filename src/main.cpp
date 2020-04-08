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
#include "museum.h"
#include "floor_wireframe.h"
#include "double_pendulum.h"
#include "rubix_cube.h"
#include "skybox.h"
#include "spotlight.h"
#include "vase.h"

char* skyboxFilenames[6] = {"textures/wall.tga", "textures/wall.tga", "textures/floor.tga", "textures/floor.tga", "textures/wall.tga", "textures/wall.tga"};

DoublePendulum doublePendulum_;
RubixCube cube_;
Spotlight spotlight_;

long int lastTime;

int updateCounter = 0;

void updateFunction(int te)
{
	long int currentTime = our_time::unixTimeMS();
	float dt = (currentTime - lastTime) / 1000.0;
	lastTime = currentTime;

	//update objects
	int res = 100;
	for(int i = 0; i < res; i++) {
		doublePendulum_.update((dt / res));
	}

	cube_.update(dt);
	spotlight_.update(dt);

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

	FloorWireframe floorWireframe = FloorWireframe();
	scene()->addDrawable(floorWireframe);

	Skybox skybox = Skybox(skyboxFilenames);
	scene()->addDrawable(skybox);

	//spotlight must go before other scene objects as it has lighting
	spotlight_ = Spotlight(GL_LIGHT7);
	*(spotlight_.position()) = Vector3f(0.0, 5.0, 0.0);
	scene()->addDrawable(spotlight_);

	Museum museum = Museum();
	scene()->addDrawable(museum);

	Vase vase = Vase();
	*(vase.position()) = Vector3f(-4.0, 0.0, 0.0);
	*(vase.scale()) = 1.5;
	scene()->addDrawable(vase);

	doublePendulum_ = DoublePendulum(Vector3f(0.5,0.5,0.5), Vector3f(0.8, 0.0, 0.0), 9.81, 0.5, 0.6, 0.5, 1., 270, 170);
	*(doublePendulum_.position()) = Vector3f(4.0, 1.8, 0.0);
	*(doublePendulum_.rotationAxis()) = Vector3f(0.0, 1.0, 0.0);
	*(doublePendulum_.rotationAngle()) = 90.;
	scene()->addDrawable(doublePendulum_);

	cube_ = RubixCube();
	*(cube_.position()) = Vector3f(0.0, 1.0, -4.0);
	*(cube_.scale()) = 0.85;
	*(cube_.rotationAxis()) = Vector3f(0., 1., 0.);
	*(cube_.rotationAngle()) = 45.;
	scene()->addDrawable(cube_);

	lastTime = our_time::unixTimeMS();
	glutTimerFunc(10, updateFunction, 1);
	graphicsMainLoop();
	return 0;
}
