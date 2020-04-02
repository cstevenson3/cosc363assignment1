/*
 * rubix_block.cpp
 *
 *  Created on: 2/04/2020
 *      Author: Cameron Stevenson
 */

#include "rubix_block.h"

#include <iostream>
#include <algorithm>

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

void RubixBlock::updateWithTurn(RubixTurn& turn) {
	vector<COLORS*> colorRotation(4); //which 4 elements of color to rotate through
	vector<int*> locationRotation(2); //which 2 elements of rotation to rotate through

	//assuming CC
	switch(*(turn.axis())) {
	case RubixTurn::AXIS::X:
		colorRotation[0] = &_colors[2]; //bottom
		colorRotation[1] = &_colors[4]; //back
		colorRotation[2] = &_colors[3]; //top
		colorRotation[3] = &_colors[5]; //front

		locationRotation[0] = &_location[1]; //Y
		locationRotation[1] = &_location[2]; //Z
		break;
	case RubixTurn::AXIS::Y:
		colorRotation[0] = &_colors[0]; //left
		colorRotation[1] = &_colors[5]; //front
		colorRotation[2] = &_colors[1]; //right
		colorRotation[3] = &_colors[4]; //back

		locationRotation[0] = &_location[2]; //Z
		locationRotation[1] = &_location[0]; //X
		break;
	case RubixTurn::AXIS::Z:
		colorRotation[0] = &_colors[0]; //left
		colorRotation[1] = &_colors[2]; //bottom
		colorRotation[2] = &_colors[1]; //right
		colorRotation[3] = &_colors[3]; //top

		locationRotation[0] = &_location[0]; //X
		locationRotation[1] = &_location[1]; //Y
		break;
	}

	if(*(turn.direction()) == RubixTurn::DIRECTION::C) {
		//reverse rotation
		std::reverse(colorRotation.begin(), colorRotation.end());
		std::reverse(locationRotation.begin(), locationRotation.end());
	}

	//location rotation
	if(*(locationRotation[0]) * *(locationRotation[1]) == 0) {
		//an edge block
		int tmpLoc = *(locationRotation[1]);
		*(locationRotation[1]) = *(locationRotation[0]);
		*(locationRotation[0]) = - tmpLoc;
	} else {
		//a corner block
		if(*(locationRotation[0]) == *(locationRotation[1])) {
			//e.g. if z is axis and x,y are same, x swaps
			*(locationRotation[0]) = - *(locationRotation[0]);
		} else {
			//e.g. if z is axis and x,y are different, y swaps
			*(locationRotation[1]) = - *(locationRotation[1]);
		}
	}

	//color rotation
	COLORS tmpCol = *(colorRotation[3]);
	for(int i = 3; i > 0; i--) {
		*(colorRotation[i]) = *(colorRotation[i - 1]);
	}
	*(colorRotation[0]) = tmpCol;
}
