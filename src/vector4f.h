/*
 * vector4f.h
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_VECTOR4F_H_
#define SRC_VECTOR4F_H_

#include <iostream>

#include "float_proxy.h"

class Vector3f;

class Vector4f {
	public:
		Vector4f();
		~Vector4f();
		Vector4f(float* array);
		Vector4f(Vector3f& vec3);
		FloatProxy operator[](int index) const;
		const float operator*(const Vector4f& right) const;
		friend std::ostream& operator<<(std::ostream& os, const Vector4f& vec);
	private:
		bool deleteVec = true;
		float* _vec;
};

#endif /* SRC_VECTOR4F_H_ */
