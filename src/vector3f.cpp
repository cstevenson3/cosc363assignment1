/*
 * vector3f.cpp
 *
 *  Created on: 18/03/2020
 *      Author: Cameron Stevenson
 */

#include "vector3f.h"


Vector3f::Vector3f() {
	_vec[0] = 0.0;
	_vec[1] = 0.0;
	_vec[2] = 0.0;
}

Vector3f::Vector3f(float f1, float f2, float f3) {
	_vec[0] = f1;
	_vec[1] = f2;
	_vec[2] = f3;
}

Vector3f::Vector3f(Vector4f vec4) {
	for(int i = 0; i < 3; i++) {
		_vec[i] = vec4[i];
	}
}

void Vector3f::delta(float deltaF1, float deltaF2, float deltaF3) {
	_vec[0] += deltaF1;
	_vec[1] += deltaF2;
	_vec[2] += deltaF3;
}

Vector3f Vector3f::operator + (const Vector3f &right) {
	Vector3f result = Vector3f(_vec[0] + right.f1(), _vec[1] + right.f2(), _vec[2] + right.f3());
	return result;
}

Vector3f& Vector3f::operator += (const Vector3f &right) {
	*this = *this + right;
	return *this;
}

float Vector3f::f1() const{
	return _vec[0];
}

float Vector3f::f2() const{
	return _vec[1];
}

float Vector3f::f3() const{
	return _vec[2];
}

std::ostream& operator<<(std::ostream &str, const Vector3f& v) {
	return str << "f1: " + std::to_string(v.f1())\
	   + ", f2: " + std::to_string(v.f2())\
	   + ", f3: " + std::to_string(v.f3());
}

float& Vector3f::operator[](int index) {
	return _vec[index];
}
