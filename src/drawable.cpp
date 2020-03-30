/*
 * drawable.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "drawable.h"

Drawable::Drawable() {
	visible = true;
	_position = Vector3f(0.0, 0.0, 0.0);
}

bool Drawable::isVisible() {
	return visible;
}

void Drawable::setVisibility(bool visible) {
	this->visible = visible;
}

Vector3f* Drawable::position() {
	return &_position;
}
