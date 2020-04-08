/*
 * drawable.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "drawable.h"

Drawable::Drawable() {
	_visible = true;
	_position = Vector3f(0.0, 0.0, 0.0);
	_rotationAxis = Vector3f(1.0, 0.0, 0.0);
	_rotationAngle = 0.0;
	_scale = 1.0;
}

bool Drawable::isVisible() {
	return _visible;
}

void Drawable::setVisibility(bool visible) {
	this->_visible = visible;
}

Vector3f* Drawable::position() {
	return &_position;
}

Vector3f* Drawable::rotationAxis() {
	return &_rotationAxis;
}

float* Drawable::rotationAngle() {
	return &_rotationAngle;
}

float* Drawable::scale() {
	return &_scale;
}
