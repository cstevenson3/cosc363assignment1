/*
 * draw_objects.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_DRAW_OBJECTS_H_
#define SRC_DRAW_OBJECTS_H_

#include "vector3f.h"

/* dimensions are width, height, depth
 * color is rgb
 */
void drawWall(Vector3f dimensions, Vector3f color);
void drawMuseumWalls(float numWalls, float radius, float height, float thickness, Vector3f color);
void drawFloorWireframe();

#endif /* SRC_DRAW_OBJECTS_H_ */
