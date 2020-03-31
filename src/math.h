/*
 * math.h
 *
 *  Created on: 18/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_MATH_H_
#define SRC_MATH_H_

#define PI (3.14159 * 1)

namespace math {
	float sin(float degrees);
	float sinrad(float radians);
	long double sinrad(long double radians);
	float cos(float degrees);
	float cosrad(float radians);
	long double cosrad(long double radians);
	float tan(float degrees);

	float sqrt(float x);

	float degreesToRadians(float degrees);
	float radiansToDegrees(float radians);

	float clamp(float val, float lower, float upper);
	float floatMod(float dividend, float divisor);
}

#endif /* SRC_MATH_H_ */
