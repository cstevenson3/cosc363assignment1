/*
 * graphics.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_GRAPHICS_H_
#define SRC_GRAPHICS_H_

#include "camera.h"

void initGraphics(int argc, char **argv);
void graphicsMainLoop();
Camera* camera();
void setCamera(Camera& camera);

#endif /* SRC_GRAPHICS_H_ */
