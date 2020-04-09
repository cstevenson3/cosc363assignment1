/*
 * museum.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_MUSEUM_H_
#define SRC_MUSEUM_H_

#include <GL/freeglut.h>

#include "drawable.h"

class Museum: public Drawable {
	public:
		Museum(char* roofTextureFilename);
		void draw();
		GLuint* roofTextureID();
	private:
		GLuint _roofTextureID;
};

#endif /* SRC_MUSEUM_H_ */
