/*
 * math.cpp
 *
 *  Created on: 18/03/2020
 *      Author: Cameron Stevenson
 */

#include "math.h"
#include <cmath>

float math::sin(float degrees) {
	return std::sin(degreesToRadians(degrees));
}

float math::cos(float degrees) {
	return std::cos(degreesToRadians(degrees));
}

float math::degreesToRadians(float degrees) {
	return degrees * 3.1415926 / 180;
}
