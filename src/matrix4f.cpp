/*
 * matrix4f.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#include "matrix4f.h"

#include <stdlib.h>
#include <iostream>

#include "float_proxy.h"

Matrix4f::Matrix4f() {
	_matrix = (float*)malloc(16 * sizeof(float));
	for(int row = 0; row < 4; row++) {
		for(int col = 0; col < 4; col++) {
			_matrix[4 * row + col] = 0.0;
		}
		_matrix[4 * row + row] = 1.0;
	}
}

Matrix4f::~Matrix4f(){
	delete _matrix;
}

Matrix4f Matrix4f::identity() {
	return Matrix4f();
}

Vector4f operator*(const Matrix4f& left, const Vector4f& right) {
	Vector4f result;
	for(int rowi = 0; rowi < 4; rowi++) {
		Vector4f row = left[rowi];
		float dot = row * right;
		result[rowi] = dot;
	}
	return result;
}

const Vector4f Matrix4f::operator[](int row) const{
	return Vector4f(_matrix + (row * 4)); // we want this returned Vector4f to point to the original _matrix entries
}

std::ostream& operator<<(std::ostream& os, const Matrix4f& mat) {
	for(int row = 0; row < 4; row++) {
		for(int col = 0; col < 4; col++) {
			os << mat._matrix[4 * row + col] << ", ";
		}
		os << std::endl;
	}
	return os;
}
