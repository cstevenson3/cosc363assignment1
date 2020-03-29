/*
 * matrix4f.cpp
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#include "matrix4f.h"

Matrix4f::Matrix4f() {
	for(int row = 0; row < 4; row++) {
		for(int col = 0; col < 4; col++) {
			_matrix[4 * row + col] = 0.0;
		}
		_matrix[4 * row + row] = 1.0;
	}
}

Matrix4f Matrix4f::identity() {
	return Matrix4f();
}

Vector4f Matrix4f::operator*(Vector4f& right) {
	Vector4f result;
	for(int rowi = 0; rowi < 4; rowi++) {
		Vector4f row = (*this)[rowi];
		float dot = row * right;
		result += dot;
	}
	return result;
}

Vector4f& Matrix4f::operator[](int row) {
	return Vector4f(_matrix + (row * 4)); // we want this returned Vector4f to point to the original _matrix entries
}
