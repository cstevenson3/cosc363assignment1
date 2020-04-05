/*
 * skybox.cpp
 *
 *  Created on: 5/04/2020
 *      Author: Cameron Stevenson
 */

#include "skybox.h"

#include "loadTGA.h"

#include "draw_objects.h"

Skybox::Skybox(char** filenames) {
	glGenTextures(6, _texIDs);

	for(int i = 0; i < 6; i++) {
		glBindTexture(GL_TEXTURE_2D, _texIDs[i]);
		loadTGA(filenames[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	}
}

GLuint* Skybox::texIDs() {
	return _texIDs;
}

void Skybox::draw() {
	drawSkybox(*this);
}
