/*
 * vector4f.h
 *
 *  Created on: 20/03/2020
 *      Author: Cameron Stevenson
 */

#ifndef SRC_VECTOR4F_H_
#define SRC_VECTOR4F_H_

class Vector3f;

class Vector4f {
	public:
		Vector4f();
		Vector4f(float* array);
		Vector4f(Vector3f& vec3);
		float operator[](int index);
		float operator*(Vector4f& right);
	private:
		float _vec[4];
};

#endif /* SRC_VECTOR4F_H_ */
