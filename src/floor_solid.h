/*
 * floor_solid.h
 *
 *  Created on: 9/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_FLOOR_SOLID_H_
#define SRC_FLOOR_SOLID_H_

#include <GL/freeglut.h>
#include "drawable.h"

class FloorSolid : public Drawable {
	public:
		FloorSolid(char* textureFilename);
		void draw();
		GLuint* textureID();
	private:
		GLuint _textureID;
};


#endif /* SRC_FLOOR_SOLID_H_ */
