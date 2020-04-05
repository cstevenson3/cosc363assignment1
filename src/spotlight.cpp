/*
 * spotlight.cpp
 *
 *  Created on: 5/04/2020
 *      Author: Cameron Stevenson
 */

#include "spotlight.h"

#include "math.h"
#include "draw_objects.h"

Spotlight::Spotlight(unsigned int lightID) {
	glEnable(lightID);
	_lightID = lightID;
	_phase = 0.0;
	*(rotationAxis()) = Vector3f(0.0, 0.0, 1.0);
}

void Spotlight::draw() {
	drawSpotlight(*this);
}

void Spotlight::update(float deltaTime) {
	float MAX_SWING = 20.0;
	float PERIOD = 2.0;
	_phase += deltaTime;
	*(rotationAngle()) = MAX_SWING * math::sinrad(_phase * 2. * PI * (1./PERIOD));
}

unsigned int* Spotlight::lightID() {
	return &_lightID;
}

float* Spotlight::phase() {
	return &_phase;
}
