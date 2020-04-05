/*
 * skybox.h
 *
 *  Created on: 5/04/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_SKYBOX_H_
#define SRC_SKYBOX_H_

#include "drawable.h"

#include <GL/freeglut.h>

class Skybox : public Drawable {
	public:
		//left, right, bottom, top, back, front
		Skybox(char** filenames);
		void draw();
		GLuint* texIDs();
	private:
		GLuint _texIDs[6];
};



#endif /* SRC_SKYBOX_H_ */
