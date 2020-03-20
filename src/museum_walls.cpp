/*
 * museum_walls.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "museum_walls.h"

#include "draw_objects.h"

void MuseumWalls::draw() {
	drawMuseumWalls(6, 5.0, 5.0, 1.0, Vector3f(0.3, 0.3, 0.3));
}
