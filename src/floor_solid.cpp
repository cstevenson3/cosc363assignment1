/*
 * floor_solid.cpp
 *
 *  Created on: 9/04/2020
 *      Author: Cameron Stevenson
 */

#include "floor_solid.h"

#include "draw_objects.h"
#include "loadTGA.h"

FloorSolid::FloorSolid(char* textureFilename) {
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);
	loadTGA(textureFilename);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void FloorSolid::draw() {
	drawFloorSolid(*this);
}


GLuint* FloorSolid::textureID() {
	return &_textureID;
}

