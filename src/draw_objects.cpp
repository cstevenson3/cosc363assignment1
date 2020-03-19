/*
 * draw_objects.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "draw_objects.h"

#include <GL/freeglut.h>

#include "math.h"

void drawWall(Vector3f dimensions, Vector3f color) {
	glColor3f(color.f1(), color.f2(), color.f3());
	glPushMatrix();
		glScalef(dimensions.f1(), dimensions.f2(), dimensions.f3());
		glutSolidCube(1.0);
	glPopMatrix();
}

void drawMuseumWalls(float numWalls, float radius, float height, float thickness, Vector3f color) {
	float angle = (360.0 / numWalls);
	for(int i = 0; i < numWalls; i++) {
		float rotation = angle * i;
		glPushMatrix();
			glRotatef(rotation, 0.0, 1.0, 0.0); // rotate wall around to a side of the building
			glTranslatef(0.0, height / 2.0, radius - thickness / 2.0); // move outside of wall to building edge
			drawWall(Vector3f(2 * radius * math::tan(angle / 2.0), height, thickness), color);
		glPopMatrix();
	}
}
