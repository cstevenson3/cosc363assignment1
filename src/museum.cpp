/*
 * museum.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "museum.h"

#include "loadTGA.h"

#include "draw_objects.h"

Museum::Museum(char* roofTextureFilename) {
	glGenTextures(1, &_roofTextureID);
	glBindTexture(GL_TEXTURE_2D, _roofTextureID);
	loadTGA(roofTextureFilename);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Museum::draw() {
	int numWalls = 8;
	float radius = 5.0;
	float height = 3.5;
	float wallThickness = 0.2;
	Vector3f color = Vector3f(0.5, 0.0, 0.5);
	drawMuseum(*this, numWalls, radius, height, wallThickness, color);
}

GLuint* Museum::roofTextureID() {
	return &_roofTextureID;
}
