/*
 * vector3f.cpp
 *
 *  Created on: 18/03/2020
 *      Author: Cameron Stevenson
 */

#include "vector3f.h"


Vector3f::Vector3f() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Vector3f::Vector3f(float f1, float f2, float f3) {
	this->x = f1;
	this->y = f2;
	this->z = f3;
}

void Vector3f::delta(float deltaF1, float deltaF2, float deltaF3) {
	this->x += deltaF1;
	this->y += deltaF2;
	this->z += deltaF3;
}

Vector3f Vector3f::operator + (const Vector3f &right) {
	Vector3f result = Vector3f(this->x + right.f1(), this->y + right.f2(), this->z + right.f3());
	return result;
}

Vector3f& Vector3f::operator += (const Vector3f &right) {
	*this = *this + right;
	return *this;
}

float Vector3f::f1() const{
	return this->x;
}

float Vector3f::f2() const{
	return this->y;
}

float Vector3f::f3() const{
	return this->z;
}
