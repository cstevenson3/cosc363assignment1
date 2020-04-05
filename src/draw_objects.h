/*
 * draw_objects.h
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_DRAW_OBJECTS_H_
#define SRC_DRAW_OBJECTS_H_

#include "vector3f.h"
#include "rubix_cube.h"
#include "skybox.h"
#include "spotlight.h"

void drawDoublePendulum(float angle1, float angle2, float length1, float length2, Vector3f armColor, Vector3f ballColor);
void drawFloorWireframe();
void drawMuseumWalls(float numWalls, float radius, float height, float thickness, Vector3f color);
void drawPendulum(float length, Vector3f armColor, Vector3f ballColor);
void drawRubixCube(RubixCube& cube);
void drawSkybox(Skybox& skybox);
void drawSpotlight(Spotlight& spotlight);
/* dimensions are width, height, depth
 * color is rgb
 */
void drawWall(Vector3f dimensions, Vector3f color);

#endif /* SRC_DRAW_OBJECTS_H_ */
