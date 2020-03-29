/*
 * matrix4f.h
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_MATRIX4F_H_
#define SRC_MATRIX4F_H_

#include "vector4f.h"

class Matrix4f {
	public:
		Matrix4f();

		static Matrix4f identity();

		Vector4f operator*(Vector4f& right);
		Vector4f& operator[](int row);
	private:
		float _matrix[16];
};

#endif /* SRC_MATRIX4F_H_ */
