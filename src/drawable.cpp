/*
 * drawable.cpp
 *
 *  Created on: 19/03/2020
 *      Author: Cameron Stevenson
 */

#include "drawable.h"

Drawable::Drawable() {
	visible = true;
}

bool Drawable::isVisible() {
	return visible;
}

void Drawable::setVisibility(bool visible) {
	this->visible = visible;
}
