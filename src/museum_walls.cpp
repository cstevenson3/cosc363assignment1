/*
 * museum_walls.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "museum_walls.h"

#include "draw_objects.h"

void MuseumWalls::draw() {
	int numWalls = 6;
	float radius = 5.0;
	float height = 3.5;
	float wallThickness = 0.2;
	Vector3f color = Vector3f(0.3, 0.3, 0.3);
	drawMuseumWalls(numWalls, radius, height, wallThickness, color);
}
