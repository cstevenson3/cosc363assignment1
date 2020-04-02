/*
 * rubix_turn.cpp
 *
 *  Created on: 3/04/2020
 *      Author: Cameron Stevenson
 */

#include "rubix_turn.h"

#include <iostream>

using namespace std;

RubixTurn::AXIS* RubixTurn::axis() {
	return &_axis;
}

RubixTurn::SIDE* RubixTurn::side() {
	return &_side;
}

RubixTurn::DIRECTION* RubixTurn::direction() {
	return &_direction;
}

float* RubixTurn::progress() {
	return &_progress;
}

vector<vector<int> > RubixTurn::affectedLocations() {
	vector<vector<int> > _affectedLocations(9, vector<int> (3, 0));

	int faceConstant = _side == SIDE::NEGATIVE ? -1: 1;
	int i = 0;
	switch(_axis) {
	case X:
		for(int y = -1; y < 2; y++) {
			for(int z = -1; z < 2; z++) {
				_affectedLocations[i][0] = faceConstant;
				_affectedLocations[i][1] = y;
				_affectedLocations[i][2] = z;
				i += 1;
			}
		}
		break;
	case Y:
		for(int x = -1; x < 2; x++) {
			for(int z = -1; z < 2; z++) {
				_affectedLocations[i][0] = x;
				_affectedLocations[i][1] = faceConstant;
				_affectedLocations[i][2] = z;
				i += 1;
			}
		}
		break;
	case Z:
		for(int x = -1; x < 2; x++) {
			for(int y = -1; y < 2; y++) {
				_affectedLocations[i][0] = x;
				_affectedLocations[i][1] = y;
				_affectedLocations[i][2] = faceConstant;
				i += 1;
			}
		}
		break;
	}
	return _affectedLocations;
}
