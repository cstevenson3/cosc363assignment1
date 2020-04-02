/*
 * rubix_block.cpp
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#include "rubix_block.h"

RubixBlock::RubixBlock() {
	for(int i = 0; i < 6; i++) {
		_colors[i] = COLORS::INSIDE;
	}
}

int* RubixBlock::location() {
	return _location;
}

RubixBlock::COLORS* RubixBlock::colors() {
	return _colors;
}

Vector3f RubixBlock::colorToRGB(COLORS color) {
	switch(color) {
	case ORANGE:
		return Vector3f(1., 0.6, 0.);
	case RED:
		return Vector3f(1., 0., 0.);
	case YELLOW:
		return Vector3f(1., 1., 0.);
	case WHITE:
		return Vector3f(1., 1., 1.);
	case BLUE:
		return Vector3f(0., 0., 1.);
	case GREEN:
		return Vector3f(0., 1., 0.);
	case INSIDE:
		return Vector3f(0.5, 0.5, 0.5);
	default:
		return Vector3f(1., 0., 1.); // purple if error
	}
}
