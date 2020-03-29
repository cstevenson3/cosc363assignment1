/*
 * draw_objects.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "draw_objects.h"

#include <GL/freeglut.h>

#include "math.h"
#include "vector3f.h"

void drawWall(Vector3f dimensions, Vector3f color) {
	glColor3f(color.f1(), color.f2(), color.f3());
	glPushMatrix();
		glScalef(dimensions.f1(), dimensions.f2(), dimensions.f3());
		glutSolidCube(1.0);
	glPopMatrix();
}

void drawRoofSection(float height, float radius, float outerWidth, float wallThickness, Vector3f color) {
	Vector3f apex = Vector3f(0, height, 0);
	Vector3f leftOuter = Vector3f(-outerWidth / 2, 0, radius);
	Vector3f rightOuter = Vector3f(outerWidth / 2, 0, radius);
	glBegin(GL_TRIANGLES);
		//outer roof
		glVertex3f(apex[0], apex[1], apex[2]);
		glVertex3f(leftOuter[0], leftOuter[1], leftOuter[2]);
		glVertex3f(rightOuter[0], rightOuter[1], rightOuter[2]);
	glEnd();
}

void drawMuseumWalls(float numWalls, float radius, float height, float thickness, Vector3f color) {
	float angle = (360.0 / numWalls);
	for(int i = 1; i < numWalls; i++) {
		float rotation = angle * i;
		float outerWidth = 2 * radius * math::tan(angle / 2.0);
		glPushMatrix();
			glRotatef(rotation, 0.0, 1.0, 0.0); // rotate wall around to a side of the building
			glPushMatrix();
				glTranslatef(0.0, height / 2.0, radius - thickness / 2.0); // move outside of wall to building edge
				drawWall(Vector3f(outerWidth, height, thickness), color);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, height, 0);
				drawRoofSection(height, radius, outerWidth, thickness, color);
			glPopMatrix();
		glPopMatrix();
	}
}

void drawFloorWireframe() {
	glDisable(GL_LIGHTING);
	glColor3f(0., 0.5,  0.);

	for(int i = -50; i <= 50; i ++)
	{
		glBegin(GL_LINES);
			glVertex3f(-50, 0.0, i);
			glVertex3f(50, 0.0, i);
			glVertex3f(i, 0.0, -50);
			glVertex3f(i, 0.0, 50);
		glEnd();
	}
	glEnable(GL_LIGHTING);
}
