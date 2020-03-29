/*
 * matrix4f.h
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_MATRIX4F_H_
#define SRC_MATRIX4F_H_

#include <iostream>

#include "vector4f.h"

class Matrix4f {
	public:
		Matrix4f();
		~Matrix4f();

		static Matrix4f identity();
		friend Vector4f operator*(const Matrix4f& left, const Vector4f& right);
		const Vector4f operator[] (int row) const;
		friend std::ostream& operator<<(std::ostream& os, const Matrix4f& mat);
	private:
		float* _matrix;
};

#endif /* SRC_MATRIX4F_H_ */
