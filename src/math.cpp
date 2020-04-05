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

//float math::sinrad(float radians) {
//	return std::sin(radians);
//}

long double math::sinrad(long double radians) {
	return std::sin(radians);
}

float math::cos(float degrees) {
	return std::cos(degreesToRadians(degrees));
}

float math::cosrad(float radians) {
	return std::cos(radians);
}

long double math::cosrad(long double radians) {
	return std::cos(radians);
}

float math::tan(float degrees) {
	return std::tan(degreesToRadians(degrees));
}

float math::sqrt(float x) {
	return std::sqrt(x);
}

long double math::sqrt(long double x) {
	return std::sqrt(x);
}

float math::degreesToRadians(float degrees) {
	return degrees * 3.1415926 / 180;
}

float math::radiansToDegrees(float radians) {
	return radians * 180. / 3.1415926 ;
}

float math::clamp(float val, float lower, float upper) {
	float result = val;
	if(result < lower) {
		result = lower;
	}
	if(result > upper) {
		result = upper;
	}
	return result;
}

float math::floatMod(float dividend, float divisor) {
	return std::fmod(dividend, divisor);
}
