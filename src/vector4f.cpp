/*
 * vector4f.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */


#include "vector4f.h"
#include "float_proxy.h"

Vector4f::Vector4f() {
	for(int i = 0; i < 4; i++) {
		_vec[i] = 0.0;
	}
}

Vector4f::Vector4f(float* array) {
	_vec = array;
}

Vector4f::Vector4f(Vector3f vec3) {
	for(int i = 0; i < 3; i++) {
		_vec[i] = vec3[i];
	}
	_vec[3] = 0.0;
}

float Vector4f::operator[](int index) {
	return FloatProxy(_vec + index);
}

float Vector4f::operator*(Vector4f& right) {
	float result = 0.0;
	for(int i = 0; i < 4; i++) {
		result += _vec[i] * right[i];
	}
}
