/*
 * vector4f.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */


#include "vector4f.h"

#include <stdlib.h>
#include <iostream>

#include "vector3f.h"
#include "float_proxy.h"

Vector4f::Vector4f() {
	_vec = (float*)malloc(4 * sizeof(float));
	for(int i = 0; i < 4; i++) {
		_vec[i] = 0.0;
	}
}

Vector4f::~Vector4f() {
	if(deleteVec) {
		delete _vec;
	}
}

Vector4f::Vector4f(float* array) {
	deleteVec = false;
	_vec = array;
}

Vector4f::Vector4f(Vector3f& vec3) {
	_vec = (float*)malloc(4 * sizeof(float));
	for(int i = 0; i < 3; i++) {
		_vec[i] = vec3[i];
	}
	_vec[3] = 0.0;
}

FloatProxy Vector4f::operator[](int index) const{
	return FloatProxy(_vec + index);
}

const float Vector4f::operator*(const Vector4f& right) const{
	float result = 0.0;
	for(int i = 0; i < 4; i++) {
		result += _vec[i] * right[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Vector4f& vec) {
	for(int i = 0; i < 4; i++) {
		os << vec._vec[i] << ", ";
	}
	return os;
}
