/*
 * museum.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "museum.h"

#include "draw_objects.h"

void Museum::draw() {
	int numWalls = 8;
	float radius = 5.0;
	float height = 3.5;
	float wallThickness = 0.2;
	Vector3f color = Vector3f(0.5, 0.0, 0.5);
	drawMuseum(numWalls, radius, height, wallThickness, color);
}
